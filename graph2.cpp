//graph using array with each row having different size
//in this code I have written BFS traversal of the graph
#include<iostream>
#include<queue>
#include<algorithm>
#include<iterator>
#include<stack>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of nodes in the graph : ";
    cin>>n;

    int *graph[n+1];
    for(int i=1;i<=n;i++)
    {
        int an;
        cout<<"Enter number of nodes adjacent to "<<i<<" : ";
        cin>>an;
        graph[i]=new int[an+2];
        graph[i][0]=i;
        for(int j=1;j<=an;j++)
        {
            cout<<"Enter the node : ";
            cin>>graph[i][j];
            cout<<endl;
        }
        graph[i][an+1]=-1;
        cout<<endl;
    }
    // Displaying the compact list
    cout<<"\nThe compact list is as below : "<<endl;
    for(int i=1;i<=n;i++)
    {
        int j=0;
        while(graph[i][j]!=-1)
        {
            cout<<graph[i][j]<<" --> ";
            j++;
        }
        cout<<"\n";
    }
    // Breadth first search traversal of the graph.
    // Starting from 1st node i.e node number 1
    queue<int> q;
    int visited[n+1];
    for(int i=1;i<=n;i++)
    visited[i]=0;
    int node;
    cout<<"\nEnter the node with which you want to start traversing : ";
    cin>>node;
    q.push(node);
    cout<<"The Breadth First traversal of the graph is : \n";
    while(!q.empty())
    {
        int node_value=q.front();
        q.pop();
        if(visited[node_value]==0)
        {
            cout<<node_value<<" --> ";
            visited[node_value]=1;
            int i=node_value;
            int j=1;
            while(graph[i][j]!=-1)
            {
                q.push(graph[i][j]);
                j++;
            }
        }
    }
    cout<<"\nDepth First Traversal of graph is : \n";
    //Depth First Traversal of the graph.
    for(int i=1;i<=n;i++)
    visited[i]=0;
    stack<int> s;
    s.push(node);
    while(!s.empty())
    {
        int node_value=s.top();
        s.pop();
        if(visited[node_value]==0)
        {
            int i=node_value;
            cout<<node_value<<" --> ";
            visited[i]=1;
            int j=0;
            while (graph[i][j]!=-1)
            {
                s.push(graph[i][j]);
                j++;
            }
        }
    }

}