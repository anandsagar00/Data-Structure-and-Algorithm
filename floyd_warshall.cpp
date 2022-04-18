//In this code I have tried to print all pair shortest path using Floyd-Warshall's algorithm
//Explanation of algorithm : https://www.youtube.com/watch?v=pgNE06YbDZ8

#include<iostream>
using namespace std;

void floyd_warshal(int **arr,int n)
{
    int f=1;
    while(f<n+1)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int via_prev_path=arr[i][f-1]+arr[f-1][j];
                if(via_prev_path<arr[i][j])
                arr[i][j]=via_prev_path;
            }
        }
        f=f+1;
    }
}

int main()
{
    int n;
    cout<<"\nEnter total number of vertices : ";
    cin>>n;

    int **arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                arr[i][j]=0;
            }
            else
            arr[i][j]=99999;//this larger value denotes infinity
        }
    }
    int edges;
    cout<<"\nEnter total number of edges : ";
    cin>>edges;
    for(int i=1;i<=edges;i++)
    {
        int u,v,w;
        cout<<"\nEnter starting vertex : ";
        cin>>u;
        cout<<"\nEnter ending vertex : ";
        cin>>v;
        cout<<"\nEnter weight of the edge : ";
        cin>>w;
        arr[u][v]=w;
    }
    floyd_warshal(arr,n);
    for(int i=0;i<n;i++)
    {
        cout<<endl;
        for(int j=0;j<n;j++)
        cout<<arr[i][j]<<" ";
    }
}