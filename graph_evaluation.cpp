#include<iostream>
using namespace std;
struct graph_node
{
    int edge;
    int weight;
};
void dfs(graph_node **arr,int n,int visited[],int &dfs_weight,int start)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i].edge==1 && visited[i]==0)
            {
                dfs_weight=dfs_weight+arr[start][i].weight;
                dfs(arr,n,visited,dfs_weight,i);
            }
        }
    }
}
void bfs(graph_node **arr,int n,int &bfs_weight,int start,int visited[])
{
    int q[100];
    int front=-1;
    int rear=-1;
    rear++;
    q[rear]=start;
    while(front<rear)
    {
        front++;
        int node_value=q[front];
        if(visited[node_value]==0)
        {
            visited[node_value]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[node_value][i].edge==1 && visited[i]==0)
                {
                    bfs_weight=bfs_weight+arr[node_value][i].weight;
                    rear++;
                    q[rear]=i;
                }
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter total number of vertices in the graph : ";
    cin>>n;
    graph_node **arr=new graph_node*[n];
    //creating an empty adjacency matrix
    for(int i=0;i<n;i++)
    {
        arr[i]=new graph_node[n];
        for(int j=0;j<n;j++)
        {
            arr[i][j].edge=0;
            arr[i][j].weight=0;
        }
    }
    int e;
    cout<<"Enter number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        cout<<"\nEnter starting vertex : ";
        cin>>u;
        cout<<"\nEnter ending vertex : ";
        cin>>v;
        cout<<"\nEnter weight of the edge : ";
        cin>>w;
        arr[u][v].edge=1;
        arr[u][v].weight=w;
        arr[v][u].edge=1;
        arr[v][u].weight=w;
    }
    int dfs_weight=0;
    int bfs_weight=0;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(arr,n,visited,dfs_weight,i);
        }
    }
    cout<<"\nTotal cost according to dfs is : "<<dfs_weight*100<<endl;
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(arr,n,bfs_weight,i,visited);
        }
    }
    cout<<"\nTotal cost according to bfs is : "<<bfs_weight*100<<endl;
}