#include<iostream>
#include<limits.h>
using namespace std;

struct priority_queue
{
    int weight;
    int node;
};

priority_queue front(priority_queue pq[],int n)
{
    priority_queue temp;
    temp.weight=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(pq[i].weight!=-1 && pq[i].weight<temp.weight)
        temp=pq[i];
    }
    return temp;
}

bool isEmpty(priority_queue pq[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(pq[i].node!=-1 || pq[i].weight!=-1)
        return false;
    }
    return true;
}

void dequeue(priority_queue pq[],int n,priority_queue temp)
{
    for(int i=0;i<n;i++)
    {
        if(pq[i].node==temp.node && pq[i].weight==temp.weight)
        {
            pq[i].weight=-1;
            pq[i].node=-1;
        }
    }
}
void dijkstra(int **arr,int n,int distance[],int source)
{
    priority_queue pq[100];
    for(int i=0;i<100;i++)
    {
        pq[i].weight=-1;
        pq[i].node=-1;
    }
    distance[source]=0;
    int l=0;
    pq[l].node=source;
    pq[l].weight=0;
    while(!isEmpty(pq,l+1))
    {
        priority_queue t=front(pq,l+1);
        dequeue(pq,n,t);

        int prev_dist=t.weight;
        int node=t.node;
        for(int i=0;i<n;i++)
        {
            if(arr[node][i]!=0)
            {
                int curr_dist=prev_dist+arr[node][i];
                if(curr_dist<distance[i])
                {
                    distance[i]=curr_dist;
                    l=l+1;
                    pq[l].node=i;
                    pq[l].weight=distance[i];
                }
            }
        }
    }
}

int main()
{
    int n;
    cout<<"Enter total number of vertices : ";
    cin>>n;

    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    cout<<"\nEnter total number of edges : ";
    cin>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cout<<"Enter starting vertex,ending vertex and weight of edge : ";
        cin>>u>>v>>w;
        arr[u][v]=w;
    }
    int distance[n];
    for(int i=0;i<n;i++)
    {
        distance[i]=99999;
    }
    int source;
    cout<<"\nEnter source node : ";
    cin>>source;
    dijkstra(arr,n,distance,source);
    for(int i=0;i<n;i++)
    {
        if(distance[i]<9999)
        cout<<"From "<<source<<" to "<<i<<" : "<<distance[i]<<endl;
        else
        cout<<"From "<<source<<" to "<<i<<" : ----"<<endl;
    }
}