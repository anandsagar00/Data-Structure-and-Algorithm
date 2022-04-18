//Check if there is a path between two nodes or not
#include<iostream>
#include<string>
using namespace std;

int *visited;
bool has_path(int **arr,int n,int s,int e)
{
    if(s==e)
    {
        return true;
    }
    else
    {
        //visited[s]=1;
        if(visited[s]==0)
        {
            visited[s]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[s][i]==0)
            continue;
            bool neighbourHasPath=has_path(arr,n,i,e);
            if(neighbourHasPath==true)
            return neighbourHasPath;
        }
        }
    }
    return false;
}
int main()
{
    int n;
    cout<<"Enter number of vertices : ";
    cin>>n;
    int** arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }
    int e;
    cout<<"Enter number of edges : ";
    cin>>e;
    for(int i=0;i<e;i++)
    {
        int u,v;
        cout<<"Enter the starting vertex of edge : ";
        cin>>u;
        cout<<endl;
        cout<<"Enter the ending vertex of the edge : ";
        cin>>v;
        cout<<endl;
        arr[u][v]=1;
        arr[v][u]=1;
    }
    visited=new int[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    int s,e1;
    cout<<"Enter the start vertex : ";
    cin>>s;
    cout<<"Enter the end vertex : ";
    cin>>e1;
    cout<<has_path(arr,n,s,e1);

}