//check bipartite using DFS

//a graph is said to be a bipartite graph iff it can be colored with exactly 2 colors without having the same colour in adjacent node
/*
Sample inputs
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
output : The given graph is not a bipartite graph.
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

output : The given graph is not a bipartite graph.

8
8
0 1
1 2
2 3
1 6
6 5
5 4
4 3
4 7

output : The given graph is a bipartite graph.

5
4
0 1
1 3
3 4
4 2

output : The given graph is a bipartite graph.

7
6
0 1
1 3
3 4
4 2
3 5
3 6

output : The given graph is a bipartite graph.
*/
#include<iostream>
using namespace std;

bool checkBipartite(int **arr,int n,int visited[],int color[],int start)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i]==0)
            continue;
            if(start==i)
            continue;
                if(color[i]==-1)
                {
                    if(color[start]==0)
                    color[i]=1;
                    else
                    color[i]=0;
                }
                else
                {
                    if(color[i]==color[start])
                    return false;
                }
                if(!checkBipartite(arr,n,visited,color,i))
                return false;
        }
    }
    return true;
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
    int color[n];
    for(int i=0;i<n;i++)
    {
        color[i]=-1;
        visited[i]=0;
    }
    color[0]=0;
    if(checkBipartite(arr,n,visited,color,0))
    cout<<"The given graph is a bipartite graph."<<endl;
    else
    cout<<"The given graph is not a bipartite graph."<<endl;
}