//in this code I have done topological sorting over a Directed Acyclic Graph(DAG)
//using DFS algorithm
//with the help of a stack
//definition : https://www.geeksforgeeks.org/topological-sorting/
//video link : https://www.youtube.com/watch?v=Yh6EFazXipA&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=13&t=54s
/*
Sample Input : 6 6 5 0 5 2 4 0 4 1 2 3 3 1
Output : 5 4 2 3 1 0
*/
#include<iostream>
#include<stack>
#include<algorithm>
#include<iterator>
using namespace std;

void dfs_topological(int **arr,int n,int visited[],stack <int> &s,int start)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i]==0 || visited[i]==1)
            continue;
            dfs_topological(arr,n,visited,s,i);
        }
        s.push(start);
    }
}
int main()
{
    int n;
    cout<<"Enter number of vertices in the graph : ";
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    cout<<"Enter total number of edges in the graph : ";
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cout<<"Enter starting and ending vertex of the edge : ";
        cin>>u>>v;
        arr[u][v]=1;//since it is a directed graph
    }
    stack<int> s;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        dfs_topological(arr,n,visited,s,i);
    }
    cout<<"\nTopological sorting of the given graph is : \n";
    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
}