//detect cycle in a graph which doesn't have component
//using BFS

#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

bool cycleExists(int **arr,int n)
{
    //using bfs 
    //only for the graph which doesn't have componenets
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    int prev=-1;
    queue<int> q;
    q.push(0);
    while(!q.empty())
    {
        int node_value=q.front();
        q.pop();
        if(visited[node_value]==1 && node_value!=prev)
        return true;
        if(visited[node_value]==0)
            {
                visited[node_value]=1;
                for(int i=0;i<n;i++)
                {
                    if(arr[node_value][i]==0)
                    continue;
                    if(i==node_value)
                    continue;
                    if(i!=prev)
                    q.push(i);
                }
                prev=node_value;
            }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter number of vertices in a graph : ";
    cin>>n;
    cout<<endl;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    cout<<"Enter no. of edges : ";
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cout<<"Start vertex : ";
        cin>>u;
        cout<<"End vertex : ";
        cin>>v;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    if(cycleExists(arr,n))
    cout<<"Yes cycle exitsts."<<endl;
    else
    cout<<"Cycle doesn't exists."<<endl;
}