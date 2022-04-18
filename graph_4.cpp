//print all sorts of possible paths between two nodes
#include<iostream>
#include<string>
using namespace std;
void print_path(int **arr,int n,int s,int e,string str,int visited[])
{
    if(s==e)
    {
        cout<<str<<s<<endl;
        return;
    }
    else
    {
        if(visited[s]==0)
        {
            visited[s]=1;
            str=str+to_string(s)+" --> ";
            for(int i=0;i<n;i++)
            {
                if(i==s)
                continue;
                if(arr[s][i]==0)
                continue;
                if(visited[i]==0)
                {
                    print_path(arr,n,i,e,str,visited);
                    visited[i]=0;
                }
            }
        }
    }
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
    int *visited=new int[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    int s,e1;
    cout<<"Enter the start vertex : ";
    cin>>s;
    cout<<"Enter the end vertex : ";
    cin>>e1;
    cout<<endl;
    print_path(arr,n,s,e1,"",visited);

}