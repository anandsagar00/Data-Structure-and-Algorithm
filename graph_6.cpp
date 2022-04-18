//detect cycle in a graph using DFS algorithm
#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<iterator>
#include<algorithm>
using namespace std;
//Sample test cases
/*
7
10
0 1
0 2
1 2
1 3
2 4
3 4
3 5
4 5
3 6
5 6
output : cycle exists
9
9
0 1
1 3
2 4
3 4
3 5
3 6
5 7
6 8
7 8
output : cycle exists
5
4
0 1
1 3
3 4
4 2
output : cycle doesn't exists
7
6
0 1
1 3
3 4
4 2
3 5
3 6
output : cycle doesn't exists
*/
bool cycleExists(int **arr,int n,int start,int prev,int visited[])
{
    if(visited[start]==1 && start!=prev)
    return true;
    if(visited[start]==0)
    {
        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i]==0)
            continue;
            if(i==start)
            continue;
            if(i!=prev)
            if(cycleExists(arr,n,i,start,visited))
            return true;
        }
    }
    return false;
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
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    if(cycleExists(arr,n,0,-1,visited))
    cout<<"Yes cycle exitsts."<<endl;
    else
    cout<<"Cycle doesn't exists."<<endl;
}