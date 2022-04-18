#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    printf("Enter number of vertices : ");
    scanf("%d",&n);
    //creating an adjacency matrix
    int arr[n][n];
    //first initialising all 
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        arr[i][j]=0;
    }
    int edges;
    printf("\nEnter total number of edges : ");
    scanf("%d",&edges);
    for(int i=0;i<edges;i++)
    {
        int u,v,w;
        printf("\nEnter starting vertex : ");
        scanf("%d",&u);
        printf("\nEnter ending vertex : ");
        scanf("%d",&v);
        printf("\nEnter weight of the edge : ");
        scanf("%d",&w);
        arr[u][v]=w;
        arr[v][u]=w;
    }

}