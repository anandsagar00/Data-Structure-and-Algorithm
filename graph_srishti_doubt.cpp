#include<iostream>
using namespace std;

void dfs(int **arr,int n,int visited[],int start)
{
    cout<<start<<" ";
    visited[start]=1;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0 && arr[start][i]==1)
        dfs(arr,n,visited,i);
    }
}

int main()
{
    int **arr;
    int n;
    cout<<"Enter the number of vertices in graph : ";
    cin>>n;
    arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    cout<<"\nEnter number of edges in the graph : ";
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        cout<<"Enter starting vertex of the edge : ";
        int u,v;
        cin>>u;
        cout<<"Enter ending vertex of the edge : ";
        cin>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    dfs(arr,n,visited,0);
}