//KAHN's algorithm

//in this code I have done topological sorting over a Directed Acyclic Graph(DAG)
//using BFS algorithm
//definition : https://www.geeksforgeeks.org/topological-sorting/
//video link : https://www.youtube.com/watch?v=rZv_jHZva34&list=PLgUwDviBIf0rGEWe64KWas0Nryn7SCRWw&index=14

//we will be using an indegree array and a queue

/*
Sample Input : 6 6 5 0 5 2 4 0 4 1 2 3 3 1
Output : 4 5 0 2 3 1
*/
#include<iostream>
#include<queue>
#include<iterator>
#include<algorithm>
using namespace std;

void toposort_bfs(int **arr,int n,int indegree[],int visited[])
{
    //first we will push all those nodes in the queue which has indegree 0
    queue<int> q;
    for(int i=0;i<n;i++)
    {
        if(indegree[i]==0)
        q.push(i);
    }
    cout<<"\n";
    while(!q.empty())
    {
        int node_value=q.front();
        q.pop();
        if(visited[node_value]==0)
        {
            cout<<node_value<<" ";
            visited[node_value]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[node_value][i]==0 || visited[i]==1)
                continue;
                indegree[i]=indegree[i]-1;
                if(indegree[i]==0)
                q.push(i);
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter total number of nodes : ";
    cin>>n;
    int **arr=new int*[n];
    int visited[n];
    int indegree[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        visited[i]=0;
        indegree[i]=0;
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    cout<<"\nEnter total number of edges in the graph : ";
    cin>>edges;
    for(int i=0;i<edges;i++)
    {
        int u,v;
        cout<<"\nEnter starting and ending vertex of the edge : ";
        cin>>u>>v;
        arr[u][v]=1;
        indegree[v]+=1;
    }
    toposort_bfs(arr,n,indegree,visited);
    
}