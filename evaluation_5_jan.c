#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

typedef struct edges
{
    int u;
    int v;
    int weight;
    int water_consumption;
}edges;

typedef struct priority_queue
{
    int distance;
    int node;
}pq;

pq front(pq p[],int n)
{
    pq temp;
    temp.distance=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(p[i].distance < temp.distance && p[i].distance!=-1)
        {
            temp=p[i];
        }
    }
    return temp;
}
void dequeue(pq p[],int n)
{
    pq temp=front(p,n);
    for(int i=0;i<n;i++)
    {
        if(temp.distance==p[i].distance && temp.node==p[i].node)
        {
            p[i].distance=-1;
            p[i].node=-1;
        }
    }
}
int isEmpty(pq p[],int n)
{
    for(int i=0;i<n;i++)
    {
        if(p[i].node!=-1)
        return 0;
    }
    return 1;
}
void dijkstra(int **arr,int n,int city_number)
{
    int dist[n];
    for(int i=0;i<n;i++)
    dist[i]=7726;
    dist[0]=0;
    pq p[100];
    for(int i=0;i<100;i++)
    {
        p[i].node=-1;
        p[i].distance=-1;
    }
    int l=0;
    dist[0]=0;
    p[l].distance=0;
    p[l].node=0;
    while(!isEmpty(p,l+1))
    {
        pq t=front(p,l+1);
        int node=t.node;
        int d=t.distance;
        dequeue(p,l+1);
        for(int i=0;i<n;i++)
        {
            int curr_dist=d;
            if(arr[node][i]!=0)
            {
                int next_distance=curr_dist+arr[node][i];
                if(next_distance<dist[i])
                {
                    dist[i]=next_distance;
                    l=l+1;
                    p[l].distance=next_distance;
                    p[l].node=i;
                }
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(i!=1)
        printf("Shortest path for water delivery from reservoir to house number %d of city %d is : %d.\n",i,city_number,dist[i]);
        else
        printf("Shortest path from main source to reservoir of city %d is : %d.\n",city_number,dist[i]);
    }
}
void kruskal_union(int a,int b,int arr[],int n)
{
    int temp=arr[a];
    for(int i=0;i<n;i++)
    {
        if(arr[i]==temp)
        arr[i]=arr[b];
    }
}

int kruakal_find(int a,int b,int arr[])
{
    if(arr[a]==arr[b])
    return 1;
    else
    return 0;
}
void sort_edges(edges e[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(e[j].weight>e[j+1].weight)
            {
                edges temp=e[j];
                e[j]=e[j+1];
                e[j+1]=temp;
            }
        }
    }
}
void kruskal(int **city_map,int n,int city_number)
{

    int count_edges=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(city_map[i][j]!=0)
            count_edges++;
        }
    }
    edges e[count_edges];
    int l=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<=i;j++)
        {
            if(city_map[i][j]!=0)
            {
                e[l].u=i;
                e[l].v=j;
                e[l].weight=city_map[i][j];
                e[l].water_consumption=rand()%1000;
                l=l+1;
            }
        }
    }
    sort_edges(e,count_edges);
    edges new_tree[n-1];
    int arr[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=i;
    }
    kruskal_union(e[0].u,e[0].v,arr,n);
    new_tree[0]=e[0];
    int j=1;
   for(int i=1;i<count_edges && j<n-1;i++)
   {
       edges temp_edge=e[i];
       if(!kruakal_find(temp_edge.u,temp_edge.v,arr))
       {
           kruskal_union(temp_edge.u,temp_edge.v,arr,n);
           new_tree[j++]=e[i];
       }
   }
   int total_length_of_pipe=0;
   int total_water_consumed=0;
   printf("pipe-line plan for city %d would look like : \n",city_number);
   for(int i=0;i<n-1;i++)
   {
       printf("%d %d %d\n",new_tree[i].u,new_tree[i].v,new_tree[i].weight);
       total_length_of_pipe+=new_tree[i].weight;
       total_water_consumed+=new_tree[i].water_consumption;
   }
   printf("\n\nTotal cost of laying pipe so that all houses connect in city %d assuming cost of pipe per meter is Rs 100 is : %d \n",city_number,total_length_of_pipe*100);
   printf("\nTotal consumption of water in city %d is : %d\n\n",city_number,total_water_consumed);
   
}
int main()
{
    int city1[][7]={
                    {0,4,0,0,0,0,0},
                    {4,0,5,0,0,0,0},
                    {0,5,0,10,12,0,15},
                    {0,0,10,0,11,0,0},
                    {0,0,12,11,0,13,0},
                    {0,0,0,0,13,0,14},
                    {0,0,15,0,0,14,0}
    };
    int **city1_map=(int **)malloc(sizeof(int *)*7);
    for(int i=0;i<7;i++)
    {
        city1_map[i]=(int *)malloc(sizeof(int)*7);
        for(int j=0;j<7;j++)
        city1_map[i][j]=city1[i][j];
    }
    printf("\n\n");
    kruskal(city1_map,7,1);
    int city2[][7]={
                    {0,9,0,0,0,0,0},
                    {0,0,10,0,11,0,18},
                    {0,10,0,16,0,0,0},
                    {0,0,16,0,0,0,0},
                    {0,11,0,0,0,14,0},
                    {0,0,0,0,14,0,0},
                    {0,18,0,0,0,0,0}
    };
    int **city2_map=(int **)malloc(sizeof(int *)*7);;
    for(int i=0;i<7;i++)
    {
        city2_map[i]=(int *)malloc(sizeof(int )*7);;
        for(int j=0;j<7;j++)
        city2_map[i][j]=city2[i][j];
    }
    printf("\n\n");
    kruskal(city2_map,7,2);
    int city3[][5]={
                    {0,6,0,0,0},
                    {0,0,17,7,0},
                    {0,17,0,0,6},
                    {0,7,0,0,9},
                    {0,0,6,9,0}
    };
    int **city3_map=(int **)malloc(sizeof(int *)*5);
    for(int i=0;i<5;i++)
    {
        city3_map[i]=(int *)malloc(sizeof(int )*5);;
        for(int j=0;j<5;j++)
        city3_map[i][j]=city3[i][j];
    }
    printf("\n\n");
    kruskal(city3_map,5,3);
    int city4[][4]={
                    {0,19,0,0},
                    {19,0,4,2},
                    {0,4,0,3},
                    {0,2,3,0}
    };
    int **city4_map=(int **)malloc(sizeof(int *)*4);
    for(int i=0;i<4;i++)
    {
        city4_map[i]=(int *)malloc(sizeof(int )*4);;
        for(int j=0;j<4;j++)
        city4_map[i][j]=city4[i][j];
    }
    printf("\n\n");
    kruskal(city4_map,4,4);
    int city5[][5]={
                    {0,12,0,0,0},
                    {12,0,1,0,0},
                    {0,1,0,2,3},
                    {0,0,2,0,14},
                    {0,0,3,14,0}
    };
    int **city5_map=(int **)malloc(sizeof(int *)*5);;
    for(int i=0;i<5;i++)
    {
        city5_map[i]=(int *)malloc(sizeof(int )*7);;
        for(int j=0;j<5;j++)
        city5_map[i][j]=city5[i][j];
    }
    printf("\n\n");
    kruskal(city5_map,5,5);
    printf("\n\n");
    dijkstra(city1_map,7,1);
    printf("\n\n");
    dijkstra(city2_map,7,2);
    printf("\n\n");
    dijkstra(city3_map,5,3);
    printf("\n\n");
    dijkstra(city4_map,4,4);
    printf("\n\n");
    dijkstra(city5_map,5,5);
}