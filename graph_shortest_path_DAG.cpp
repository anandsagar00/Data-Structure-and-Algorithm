//find the shortest path in a wighted DAG
//video explanation link : https://www.youtube.com/watch?v=CrxG4WJotgg&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=17

//we will be store the weights along with the adjaceny list
//we need to first find the topological sorting of the DAG then we will assign weights 
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<queue>
#include<stack>
#include<utility>
#include<limits.h>
using namespace std;
void topological_sort(vector<pair<int,int> > arr[],int n,int start,int visited[],stack<int> &s)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        for(auto it:arr[start])
        {
            if(visited[it.first]==0)
            {
                topological_sort(arr,n,it.first,visited,s);
            }
        }
        s.push(start);
    }
}
void shortest_path(vector<pair<int,int> > arr[],int n,int distance[],int source)
{
    int visited[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=0;
    }
    distance[source]=0;
    stack<int> s;
    topological_sort(arr,n,source,visited,s);
    while(!s.empty())
    {
        int node_value=s.top();
        s.pop();
        if(distance[node_value]!=INT_MAX)
        {
            for(auto it:arr[node_value])
            {
                int temp_distance=distance[node_value]+it.second;
                if(temp_distance<distance[it.first])
                distance[it.first]=temp_distance;
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter number of edges in the graph : ";
    cin>>n;
    vector<pair<int,int> > arr[n];
    int edges;
    cout<<"\nEnter number of edges in the graph : ";
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        cout<<"\nEnter starting vertex : ";
        int u,v,weight;
        cin>>u;
        cout<<"\nEnter ending vertex : ";
        cin>>v;
        cout<<"\nEnter the wight of the edge : ";
        cin>>weight;
        arr[u].push_back(make_pair(v,weight));
    }
    int distance[n];
    shortest_path(arr,n,distance,0);
    for(int i=1;i<n;i++)
    {
        cout<<"\nShortest path of "<<i<<" from 0 is : "<<distance[i];
    }
}