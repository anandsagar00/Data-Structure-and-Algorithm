//In this code I have tried to generate MST using Kruskal's algorithm
//with the help of union find method

#include<iostream>
using namespace std;

//structure which stores all the edges with their weight

struct edges
{
    int u;
    int v;
    int w;
};

void kruskal_union(int a,int b,int arr[],int n)
{
    //connection to be made is to be from right to left
    int temp=arr[a];
    for(int i=0;i<n;i++)
    {
        if(arr[i]==temp)
        arr[i]=arr[b];
    }
}

int kruakal_find(int a,int b,int arr[])
{
    //returns whether both the elements belong to the same set
    if(arr[a]==arr[b])
    return 1;
    else
    return 0;
}
void kruskal_mst(edges e[],edges new_tree[],int edge,int n)
{
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    kruskal_union(e[0].u,e[0].v,arr,n);
    new_tree[0]=e[0];
    int j=1;
   for(int i=1;i<edge && j<n-1;i++)
   {
       edges temp_edge=e[i];
       if(!kruakal_find(temp_edge.u,temp_edge.v,arr))
       {
           kruskal_union(temp_edge.u,temp_edge.v,arr,n);
           new_tree[j++]=e[i];
       }
   }
}
void sort_bubble(edges e[],int edge_n)
{
    for(int i=0;i<edge_n-1;i++)
    {
        for(int j=0;j<edge_n-i-1;j++)
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

int main()
{
    int n;
    cout<<"Enter total number of vertices : ";
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }

    int edge;
    cout<<"\nEnter total edges : ";
    cin>>edge;
    edges e[edge];
    for(int i=0;i<edge;i++)
    {
        int u,v,w;
        cout<<"\nEnter starting vertex : ";
        cin>>u;
        cout<<"\nEnter ending vertex : ";
        cin>>v;
        cout<<"\nEnter the weight of the edge : ";
        cin>>w;
        e[i].u=u;
        e[i].v=v;
        e[i].w=w;
        arr[u][v]=w;
        arr[v][u]=w;
    }
    sort_bubble(e,edge);
    edges new_tree[n-1];
    kruskal_mst(e,new_tree,edge,n);
    int weight_of_mst=0;
    for(int i=0;i<n-1;i++)
    {
        weight_of_mst+=new_tree[i].w;
    }
    cout<<"\nWeight of MST is : "<<weight_of_mst<<endl;
}