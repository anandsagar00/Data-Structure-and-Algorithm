//get connceted components of a graph using BFS
#include<iostream>
#include<vector>
#include<iterator>
#include<iterator>
#include<queue>
using namespace std;
void BFS(int **arr,int n,vector < vector <int> > &v,int visited[],int start)
{
    queue <int> q;
    q.push(start);
    vector<int> vec;
    while(!q.empty())
    {
        int node=q.front();
        q.pop();
        if(visited[node]==0)
        {
            visited[node]=1;
            vec.push_back(node);
            for(int i=0;i<n;i++)
            {
                if(arr[node][i]==0)
                continue;
                if(i==node)
                continue;
                if(visited[i]==0)
                q.push(i);
            }
        }
    }
    v.push_back(vec);
}

vector<vector<int> > get_components(int **arr,int n)
{
    vector<vector<int> > v;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        BFS(arr,n,v,visited,i);
    }
    return v;
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
    vector<vector<int> > v=get_components(arr,n);
    for(auto it=v.begin();it!=v.end();it++)
    {
        cout<<"[ ";
        vector<int> component=*it;
        for(auto it1=component.begin();it1!=component.end();it1++)
        {
            cout<<*it1<<" , ";
        }
        cout<<"]"<<endl;
    }
}