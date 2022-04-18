#include<iostream>
#include<queue>
#include<iterator>
#include<algorithm>
using namespace std;
/*
4
5
0 1
1 3
3 2
2 0
0 3
*/
void dfs(int **arr,int start,int visited[],int n)
{
    if(visited[start]==0)
    {
        //cout<<start<<" ";
        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i]==0)
            continue;
            if(start==i)
            continue;
            if(visited[i]==0)
            dfs(arr,i,visited,n);
        }
    }
}
int bfs(int **arr,int start,int visited[],int n,int cisl)
{
    int total_wt=0;
    queue<int> q;
    q.push(start);
    while(!q.empty())
    {

        int node=q.front();
        q.pop();
        if(visited[node]==0)
        {
            //cout<<node<<" ";
            visited[node]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[node][i]==0)
                continue;
                if(visited[i]==0)
                {
                    q.push(i);
                    total_wt+=arr[node][i];
                }
            }
        }
    }
    cout<<"Total weight to travel isalnd "<<cisl+1<<" : "<<total_wt<<endl;
    return total_wt;
}
void print_mat(int **arr,int n)
{
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<i<<" --> ";
        for(int j=0;j<n;j++)
        {
            if(arr[i][j])
            cout<<j<<" --> ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main()
{
    int n;
    cout<<"Enter number of vertices in the graph : ";
    cin>>n;
    int **arr=new int*[n];//creating a ptr to ptr which points to the arry of pointers
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int e;
    cout<<"\nEnter number of edges in the graph : ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        cout<<"\nEnter starting vertex of edge "<<i+1<<" : ";
        int u;
        cin>>u;
        cout<<"\nEnter ending vertex of edge "<<i+1<<" : ";
        int v;
        cin>>v;
        cout<<"Enter weight of edge : ";
        int wt;
        cin>>wt;
        arr[u][v]=wt;
        arr[v][u]=wt;
    }
    print_mat(arr,n);
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    // cout<<"\nDfs traversal is : \n";
    int cisl=0;
    // for(int i=0;i<n;i++)
    // {
    //     if(visited[i]==0)
    //     {
    //         dfs(arr,i,visited,n);
    //         cisl++;
    //     }
    // }
    
    for(int i=0;i<n;i++)
    visited[i]=0;
    //cout<<"\nBFS traversal is : \n";
    int tw=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            tw=bfs(arr,i,visited,n,cisl);
            cisl++;
        }
    }
    cout<<"\n Islands count : "<<cisl;

}
/*
6
3
0 1 10
1 2 20
3 4 20
*/