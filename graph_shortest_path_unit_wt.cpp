//Find the shortest path from source node to all other nodes if the weigths of each edge is 1 
//Explanation Video Link : https://www.youtube.com/watch?v=hwCWi7-bRfI&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=16 

//Assuming that the graph is connected
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<queue>
#include<limits.h>
using namespace std;

void shortest_path(vector<int> arr[],int n,int distance[],int source)
{
    int visited[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=INT_MAX;
        visited[i]=0;
    }

    distance[source]=0;
    queue<int> q;
    q.push(source);
    while(!q.empty())
    {
        int node_value=q.front();
        q.pop();
        if(visited[node_value]==0)
        {
            visited[node_value]=1;
            for(auto it=arr[node_value].begin();it!=arr[node_value].end();it++)
            {
                int new_temp_distance=distance[node_value]+1;
                if(new_temp_distance<distance[*it])
                distance[*it]=new_temp_distance;
                if(visited[*it]==0)
                q.push(*it);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter number of vertices : ";
    cin>>n;
    vector<int> arr[n];
    int distance[n];
    int edges;
    cout<<"\nEnter number of edges : ";
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        cout<<"Enter starting and ending vertex of the edge : ";
        int u,v;
        cin>>u>>v;
        arr[u].push_back(v);
        arr[v].push_back(u);
    }
    shortest_path(arr,n,distance,0);
    for(int i=1;i<n;i++)
    {
        cout<<"\nShortest path of "<<i<<" from 0 is : "<<distance[i];
    }
}