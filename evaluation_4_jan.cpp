#include<iostream>
#include<utility>
#include<vector>
#include<queue>
using namespace std;

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
        // cout<<p.first<<endl;
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
        cout<<"Shortest path for water delivery from reservoir to house number "<<(i+1)<<" of city"<<city_number<<" is : "<<distance[i]<<endl;
        else
        cout<<"Shortest path from main source to reservoir of city"<<city_number<<" is : "<<distance[i]<<endl;
    }
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
    dijkstra(city1_map,7,1);
    cout<<endl;
    dijkstra(city2_map,7,2);
    cout<<endl;
    dijkstra(city3_map,5,3);
    cout<<endl;
    dijkstra(city4_map,4,4);
    cout<<endl;
    dijkstra(city5_map,5,5);
}