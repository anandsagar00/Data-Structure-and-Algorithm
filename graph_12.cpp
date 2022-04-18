//print Hemiltonian Path and cycle using DFS
//in path end with a dot(.)
//in cycle end with a *
#include<iostream>
#include<string>
using namespace std;

void hamiltonian(int **arr,int n,int visited[],int curr,int prev,string path)
{
    if(visited[curr]==0)
    {
        visited[curr]=1;
        int total_visited=0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==1)
            total_visited+=1;
        }
        if(total_visited==n)
        {
            cout<<path<<curr<<" ."<<endl;
        }
        path=path+to_string(curr)+" ";
        for(int i=0;i<n;i++)
        {
            if(arr[curr][i]==0)
            continue;
            if(i==curr)
            continue;
            if(visited[i]==0)
            {
                hamiltonian(arr,n,visited,i,curr,path);
            }
        }
        visited[curr]=0;
    }
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
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
    }
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        hamiltonian(arr,n,visited,i,-1,"");
    }
}