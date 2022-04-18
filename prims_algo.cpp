//In this code I have tried to implement Prim's algorithm 
#include<iostream>
#include<limits.h>
using namespace std;

struct min_tree
{
    int u;
    int v;
    int w;
};

void prims_union(int a,int b,int arr[],int n)
{
    //connection to be made is to be from right to left
    int temp=arr[a];
    for(int i=0;i<n;i++)
    {
        if(arr[i]==temp)
        arr[i]=arr[b];
    }
}

int prims_find(int a,int b,int arr[])
{
    //returns whether both the elements belong to the same set
    if(arr[a]==arr[b])
    return 1;
    else
    return 0;
}

void prims_mst(int **arr,int n,min_tree T[])
{
    int mst[n];//whether a node has been included or not
    int set[n];//stores the disjoint set
    int key[n];//stores distance of adjacent nodes
    for(int i=0;i<n;i++)
    {
        mst[i]=0;
        set[i]=-1;
        key[i]=INT_MAX;
    }
    //let us first include the 0th node

    key[0]=0;
    int count=0;
    while(count<n-1)
    {
        int min_dist_in_key=INT_MAX;
        int node=0;
        for(int i=0;i<n;i++)
        {
            if(mst[i]==0 && key[i]<min_dist_in_key)
            {
                min_dist_in_key=key[i];
                node=i;
            }
        }
        mst[node]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[node][i]!=0 && mst[i]==0 && arr[node][i]<key[i])
            {
                set[i]=node;
                key[i]=arr[node][i];
            }
        }
        count++;
    }
    int sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=key[i];
    }
    cout<<"\nTotal min cost is : "<<sum<<endl;
}

int main()
{
    int n;
    cout<<"\nEnter total number of vertices : ";
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }

    int edges;
    cout<<"\nEnter total number of edges in the graph : ";
    cin>>edges;

    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cout<<"\nEnter starting vertex : ";
        cin>>u;
        cout<<"Enter ending vertex : ";
        cin>>v;
        cout<<"Enter edge weight : ";
        cin>>w;
        arr[u][v]=w;
        arr[v][u]=w;
    }

    min_tree T[n-1];
    prims_mst(arr,n,T);
}