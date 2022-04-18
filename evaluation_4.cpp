#include<iostream>
#include<time.h>
using namespace std;

struct edges
{
    int u,v,w;
};

void union_kruskal(int arr[],int n,int a,int b)
{
    int temp=arr[a];
    for(int i=0;i<n;i++)
    {
        if(arr[i]==temp)
        arr[i]=arr[b];
    }
}

int find(int a,int b,int arr[])
{
    if(arr[a]==arr[b])
    return 1;
    else 
    return 0;
}

void sort_edges(edges e[],int en)
{
    for(int i=0;i<en-1;i++)
    {
        for(int j=0;j<en-i-1;j++)
        {
            if(e[j].w>e[j+1].w)
            {
                edges temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}

void kruskal_mst(edges e[],edges new_tree[],int n,int el)
{
    int arr[n];//this is the array which will store the disjoint set
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    union_kruskal(arr,n,e[0].u,e[0].v);
    new_tree[0]=e[0];
    int j=1;
    for(int i=1;i<el && j<n-1;i++)
    {
        edges temp=e[i];
        if(!find(temp.u,temp.v,arr))
        {
            union_kruskal(arr,n,temp.u,temp.v);
            new_tree[j++]=temp;
        }
    }
}
int partition(edges e[],int start,int end)
{
    int x=e[start].w;
    int count_smaller_than_x=0;
    for(int i=start+1;i<=end;i++)
    {
        if(e[i].w<=x) 
        count_smaller_than_x=count_smaller_than_x+1;
    }

    edges temp=e[start];
    e[start]=e[start+count_smaller_than_x];
    e[start+count_smaller_than_x]=temp;
    
    int i=start;
    int j=end;
    while(i<(start+count_smaller_than_x) && j>(start+count_smaller_than_x))
    {
        if(e[i].w<=x)
        {
            i++;
        }
        else if(e[j].w>x)
        {
            j--;
        }
        else
        {
            edges t=e[i];
            e[i]=e[j];
            e[j]=t;
            i++;
            j--;
        }
    }
    return start+count_smaller_than_x;

}
void quicksort(edges e[],int start,int end)
{
    if(start>=end)
    return;
    int pivot_point=partition(e,start,end);
    quicksort(e,start,pivot_point-1);
    quicksort(e,pivot_point+1,end);
}
int main()
{
    int n;
    cout<<"Enter total number of vertices : ";
    cin>>n;
    int el;
    cout<<"Enter total number of edges : ";
    cin>>el;
    edges e[el];
    edges e1[el];
    for(int i=0;i<el;i++)
    {
        int u,v,w;
        cout<<"Enter starting,ending vertex and edge weight : ";
        cin>>u>>v>>w;
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
        e1[i]=e[i];
    }
    double start,end;
    start=clock();
    sort_edges(e,el);
    edges new_tree[n-1];
    kruskal_mst(e,new_tree,n,el);
    int weight_of_mst=0;
    for(int i=0;i<n-1;i++)
    {
        weight_of_mst+=new_tree[i].w;
    }
    cout<<"Total weight of mst is : "<<weight_of_mst<<endl;
    end=clock();
    double total_time=(end-start)/CLOCKS_PER_SEC;
    cout<<"\nTotal time taken by kruskal's algorithm using bubble sort is : "<<total_time<<endl;
    start=clock();
    quicksort(e1,0,el-1);
    kruskal_mst(e1,new_tree,n,el);
    weight_of_mst=0;
    for(int i=0;i<n-1;i++)
    {
        weight_of_mst+=new_tree[i].w;
    }
    cout<<"Total weight of mst is : "<<weight_of_mst<<endl;
    end=clock();
    total_time=(end-start)/CLOCKS_PER_SEC;
    cout<<"Total time taken by Kruskal algorithm when we use quick sort is : "<<total_time<<endl;
    for(int i=0;i<n-1;i++)
    {
        cout<<new_tree[i].u<<" "<<new_tree[i].v<<" "<<new_tree[i].w<<endl;
    }
}