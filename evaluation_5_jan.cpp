#include<iostream>
#include<utility>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;

struct edges
{
    int u;
    int v;
    int weight;
    int water_consumption;
};
struct priority_q
{
    int node;
    int weight;
};
priority_q front(priority_q pq[],int n)
{
    priority_q p;
    p.weight=INT_MAX;
    for(int i=0;i<n;i++)
    {
        if(pq[i].weight<p.weight)
        {
            p=pq[i];
        }
    }
    return p;
}
void dijkstra(int **city_map,int n,int city_number)
{
    int distance[n];
    for(int i=0;i<n;i++)
    distance[i]=7726;
    distance[0]=0;
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    pq.push(make_pair(0,0));
    while(!pq.empty())
    {
        pair<int,int> p=pq.top();
        int curr_distance=p.first;
        int node=p.second;
        pq.pop();
        for(int i=0;i<n;i++)
        {
            int next_distance=curr_distance+city_map[node][i];
            if(city_map[node][i]!=0 && next_distance<distance[i])
            {
                distance[i]=next_distance;
                pq.push(make_pair(next_distance,i));
            }
        }
    }
    for(int i=1;i<n;i++)
    {
        if(i!=1)
        cout<<"Shortest path for water delivery from reservoir to house number "<<(i)<<" of city"<<city_number<<" is : "<<distance[i]<<endl;
        else
        cout<<"Shortest path from main source to reservoir of city"<<city_number<<" is : "<<distance[i]<<endl;
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
   cout<<"pipe-line plan for city"<<city_number<<" would look like : \n";
   for(int i=0;i<n-1;i++)
   {
       cout<<new_tree[i].u<<" "<<new_tree[i].v<<" "<<new_tree[i].weight<<endl;
       total_length_of_pipe+=new_tree[i].weight;
       total_water_consumed+=new_tree[i].water_consumption;
   }
   cout<<"\n\nTotal cost of laying pipe so that all houses connect in city"<<city_number<<"assuming cost of pipe per meter is Rs 100 is : "<<total_length_of_pipe*100<<endl;
   cout<<"\nTotal consumption of water in city"<<city_number<<" is : "<<total_water_consumed<<endl;
   cout<<endl;
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
    int **city1_map=new int*[7];
    for(int i=0;i<7;i++)
    {
        city1_map[i]=new int[7];
        for(int j=0;j<7;j++)
        city1_map[i][j]=city1[i][j];
    }
    cout<<"\n"<<endl;
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
    int **city2_map=new int*[7];
    for(int i=0;i<7;i++)
    {
        city2_map[i]=new int[7];
        for(int j=0;j<7;j++)
        city2_map[i][j]=city2[i][j];
    }
    cout<<"\n"<<endl;
    kruskal(city2_map,7,2);
    int city3[][5]={
                    {0,6,0,0,0},
                    {0,0,17,7,0},
                    {0,17,0,0,6},
                    {0,7,0,0,9},
                    {0,0,6,9,0}
    };
    int **city3_map=new int*[5];
    for(int i=0;i<5;i++)
    {
        city3_map[i]=new int[5];
        for(int j=0;j<5;j++)
        city3_map[i][j]=city3[i][j];
    }
    cout<<"\n"<<endl;
    kruskal(city3_map,5,3);
    int city4[][4]={
                    {0,19,0,0},
                    {19,0,4,2},
                    {0,4,0,3},
                    {0,2,3,0}
    };
    int **city4_map=new int*[4];
    for(int i=0;i<4;i++)
    {
        city4_map[i]=new int[4];
        for(int j=0;j<4;j++)
        city4_map[i][j]=city4[i][j];
    }
    cout<<"\n"<<endl;
    kruskal(city4_map,4,4);
    int city5[][5]={
                    {0,12,0,0,0},
                    {12,0,1,0,0},
                    {0,1,0,2,3},
                    {0,0,2,0,14},
                    {0,0,3,14,0}
    };
    int **city5_map=new int*[5];
    for(int i=0;i<5;i++)
    {
        city5_map[i]=new int[5];
        for(int j=0;j<5;j++)
        city5_map[i][j]=city5[i][j];
    }
    cout<<"\n"<<endl;
    kruskal(city5_map,5,5);
    cout<<"\n"<<endl;
    dijkstra(city1_map,7,1);
    cout<<"\n"<<endl;
    dijkstra(city2_map,7,2);
    cout<<"\n"<<endl;
    dijkstra(city3_map,5,3);
    cout<<"\n"<<endl;
    dijkstra(city4_map,4,4);
    cout<<"\n"<<endl;
    dijkstra(city5_map,5,5);
}