#include<iostream>
#include<queue>
#include<utility>
#include<string>
using namespace std;

void dijsktra(int **arr,int src,int dest,string places[])
{
    priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > pq;
    int dist[14];
    for(int i=0;i<14;i++)
    dist[i]=772681;
    dist[src]=0;
    pq.push(make_pair(0,src));
    while(!pq.empty())
    {
        pair<int,int> temp_node=pq.top();
        int curr_dist=temp_node.first;
        int node=temp_node.second;
        pq.pop();
        for(int i=0;i<14;i++)
        {
            int next_dist=curr_dist+arr[node][i];
            if(arr[node][i]!=0 && next_dist<dist[i])
            {
                dist[i]=next_dist;
                pq.push(make_pair(next_dist,i));
            }
        }
    }
    cout<<"Total distance from "<<places[src]<<" to "<<places[dest]<<" is : "<<dist[dest];
}

int main()
{
    string places[]={"Hubli","Dhadwad","Kambapur-M-Narendra","Mugad","Alanvar","Belur","Tegur"
                    "Kittur","Bidi","Nanagad","Rangarook","Mollem","Collem","Goa"};
    int array[][14]={{0,10,9,0,0,0,0,0,0,0,0,0,0,0},
                    {10,0,0,10,0,0,0,0,0,0,0,0,0,0},
                    {9,0,0,0,0,20,0,0,0,0,0,0,0,0},
                    {0,10,0,0,14,0,0,0,0,0,0,0,0,0},
                    {0,0,0,14,0,0,0,0,17,0,49,0,0,0},
                    {0,0,20,0,0,0,16,0,0,0,0,0,0,0},
                    {0,0,0,0,0,16,0,7,0,0,0,0,0,0},
                    {0,0,0,0,0,0,7,0,4,0,0,0,0,0},
                    {0,0,0,0,17,0,0,4,0,9,0,0,0,0},
                    {0,0,0,0,0,0,0,0,9,0,20,0,0,0},
                    {0,0,0,0,49,0,0,0,0,20,0,5,0,0},
                    {0,0,0,0,0,0,0,0,0,0,0,0,14,16},
                    {0,0,0,0,0,0,0,0,0,0,0,14,0,10},
                    {0,0,0,0,0,0,0,0,0,0,0,16,10,0}};
    int **arr=new int*[14];
    for(int i=0;i<14;i++)
    {
        arr[i]=new int[14];
        for(int j=0;j<14;j++)
        {
            arr[i][j]=array[i][j];
        }
    }
    dijsktra(arr,4,13,places);
}