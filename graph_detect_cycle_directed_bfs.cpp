//detect cycle in a Directed Graph using BFS
//We know that Topological sort is only possible in a graph with no Cycle i.e only in case of Directed Acyclic Graph
//we will try to generate Topological sort and if we will not be able to generate then it contains the cycle
//Kahn's Algorithm
//Video link : https://www.youtube.com/watch?v=V6GxfKDyLBM&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=15

#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<queue>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of vertices : ";
    cin>>n;
    vector<int> arr[n];
    cout<<"\nEnter number of edges in the graph : ";
    int edges;
    cin>>edges;
    int indegree[n];
    int visited[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=0;
        indegree[i]=0;
    }
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cout<<"Enter starting and ending vertices of the edge : ";
        cin>>u>>v;
        arr[u].push_back(v);
        indegree[v]++;
    }
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    int count=0;
    while(!q.empty())
    {
        int node_value=q.front();
        q.pop();
        if(visited[node_value]==0)
        {
            count++;
            visited[node_value]=1;
            for(auto it=arr[node_value].begin();it!=arr[node_value].end();it++)
            {
                if(visited[*it]==1)
                continue;
                indegree[*it]=indegree[*it]-1;
                if(indegree[*it]==0)
                q.push(*it);
            }
        }
    }
    if(n==count)
    cout<<"\nThere is no cycle in this graph.";
    else
    cout<<"\nThere exists a cycle in the graph.";
}
