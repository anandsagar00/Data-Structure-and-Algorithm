//detect cycle in a directed graph using dfs

#include<iostream>
using namespace std;
bool checkCycleDirected(int **arr,int n,int visited[],int dfsVisit[],int start)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        dfsVisit[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i]==0)
            continue;
            if(dfsVisit[i]==1)
            return true;
            if(visited[i]==0)
            {
                if(checkCycleDirected(arr,n,visited,dfsVisit,i))
                return true;
            }
        }
        dfsVisit[start]=0;
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
    }
    int visited[n];
    int dfsVisit[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        dfsVisit[i]=0;
    }
    int flag=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            if(checkCycleDirected(arr,n,visited,dfsVisit,i))
            {
                cout<<"There is a cycle in the graph.";
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    cout<<"There is no cycle in the graph."<<endl;
}