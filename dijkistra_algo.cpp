#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
#include<queue>
#include<utility>
#include<limits.h>
using namespace std;

void shortest_path(vector < pair<int,int> > graph[],int n,int source,int distance[])
{
    priority_queue< pair <int,int>,vector<pair<int,int> >,greater< pair<int,int> > > pq;
    distance[source]=0;
    pq.push(make_pair(distance[source],source));
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        int dist=p.first;
        int node=p.second;
        pq.pop();
        for(auto it=graph[node].begin();it!=graph[node].end();it++)
        {
            pair<int,int> p1=(*it);
            int next_node=p1.first;
            int next_distance=p1.second;
            if((dist+next_distance)<distance[next_node])
            {
                distance[next_node]=dist+next_distance;
                pq.push(make_pair(distance[next_node],next_node));
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter total number of vertices : ";
    cin>>n;
    vector<pair<int,int> > graph[n];
    cout<<"Enter total number of edges : ";
    int edges;
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        cout<<"\nEnter starting vertex : ";
        cin>>u;
        cout<<"\nEnter ending vertex : ";
        cin>>v;
        cout<<"\nEnter edge weight : ";
        cin>>w;
        graph[u].push_back(make_pair(v,w));
        graph[v].push_back(make_pair(u,w));
    }
    int distance[n];
    for(int i=0;i<n;i++)
    distance[i]=INT_MAX;
    int source;
    cout<<"\nEnter Source node : ";
    cin>>source;
    shortest_path(graph,n,source,distance);
    for(int i=0;i<n;i++)
    {
        cout<<"\nDistance of "<<i<<" from "<<source<<" is : "<<distance[i];
    }
}