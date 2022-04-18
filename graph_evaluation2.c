//source is assigned vertex 0 in my case

#include<stdio.h>
#include<stdlib.h>
struct graph_node
{
    int edge;
    int weight;
};
void dfs(struct graph_node **arr,int n,int visited[],int *dfs_weight,int start)
{
    if(visited[start]==0)
    {
        visited[start]=1;
        for(int i=0;i<n;i++)
        {
            if(arr[start][i].edge==1 && visited[i]==0)
            {
                *dfs_weight=(*dfs_weight)+arr[start][i].weight;
                dfs(arr,n,visited,dfs_weight,i);
            }
        }
    }
}
void bfs( struct graph_node **arr,int n,int*bfs_weight,int start,int visited[])
{
    int q[100];
    int front=-1;
    int rear=-1;
    rear++;
    q[rear]=start;
    while(front<rear)
    {
        front++;
        int node_value=q[front];
        if(visited[node_value]==0)
        {
            visited[node_value]=1;
            for(int i=0;i<n;i++)
            {
                if(arr[node_value][i].edge==1 && visited[i]==0)
                {
                    *bfs_weight=(*bfs_weight)+arr[node_value][i].weight;
                    rear++;
                    q[rear]=i;
                }
            }
        }
    }
}
int main()
{
    int n;

    printf("Enter total number of vertices in the graph : ");
    scanf ("%d",&n);
     struct graph_node **arr=(struct graph_node**)malloc(sizeof(struct graph_node)*n);
    //creating an empty adjacency matrix
    for(int i=0;i<n;i++)
    {
        arr[i]= (struct graph_node*)malloc(sizeof(struct graph_node)*n);;
        for(int j=0;j<n;j++)
        {
            arr[i][j].edge=0;
            arr[i][j].weight=0;
        }
    }
    int water[n];
    for(int i=1;i<n;i++)
    {
        //source vertex is 0 so I am not asking user to input water requirement for source vertex
        int w=(abs((rand()+1))%10000);
        if(w<1000)
        w+=2000;
        water[i]=w;
    }
    int e;
    printf("Enter number of edges : ");
    scanf("%d",&e);
    for(int i=0;i<e;i++)
    {
        int u,v,w;
        printf("\nEnter starting vertex : ");
        scanf("%d",&u);
        printf("\nEnter ending vertex : ");
        scanf("%d", &v);
        printf("\nEnter length of the pipe in inches : ");
        scanf("%d", &w);
        arr[u][v].edge=1;
        arr[u][v].weight=w;
        arr[v][u].edge=1;
        arr[v][u].weight=w;
    }
    int dfs_weight=0;
    int bfs_weight=0;
    int visited[n];
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            dfs(arr,n,visited,&dfs_weight,i);
        }
    }
    printf("\nTotal cost according to dfs is : %d\n", dfs_weight*100);
    for(int i=0;i<n;i++)
    visited[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visited[i]==0)
        {
            bfs(arr,n,&bfs_weight,i,visited);
        }
    }
    printf("\nTotal cost according to bfs is : %d\n",bfs_weight*100);
    int total_water_req=0;
    for(int i=1;i<n;i++)
    {
        total_water_req+=water[i];
    }
    printf("Total water required by all houses : %d",total_water_req);
    //assuming that water flowing at the rate of 10 inches per second
    float vol_out_per_sec=(3.14)*(1.25*1.25)*10;
    float time=total_water_req/vol_out_per_sec;
    printf("\nTotal time required to fill all houses : %f seconds",time);
}