//get connceted components of a graph using Depth First Search
/*
Sample Input
11
8
0 1
1 2
2 0
3 4
7 8
7 9
9 10
10 8

Output :
[ 0 , 1 , 2 , ]
[ 3 , 4 , ]
[ 5 , ]
[ 6 , ]
[ 7 , 8 , 10 , 9 , ]
*/
#include<iostream>
#include<vector>
#include<iterator>
#include<iterator>
#include<queue>
using namespace std;
void DFS(int **arr,int n,vector <int> &v,int visited[],int start)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        v.push_back(start);
        for(int i=0;i<n;i++)
        {
            if(arr[start][i]==0)
            continue;
            if(i==start)
            continue;
            if(visited[i]==0)
            DFS(arr,n,v,visited,i);
        }
    }
}

vector<vector<int> > get_components(int **arr,int n)
{
    vector<vector<int> > vec;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        if(visited[i]==0)
        {
            DFS(arr,n,v,visited,i);
            vec.push_back(v);
        }
    }
    return vec;
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