//this program demonstrates the input in a graph using compact list method.

#include<iostream>
#include<vector>
#include<iterator>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of vertices in a graph : ";
    cin>>n;
    vector <vector <int> > graph;
    for(int i=0;i<n;i++)
    {
        vector<int> v;
        while(true)
        {
            int n1;
            cout<<"\nEnter the adjacent vertices of "<<(i+1)<<" : ";
            cin>>n1;
            if(n1>0)
            {
                v.push_back(n1);
            }
            else
            break;
        }
        graph.push_back(v);
    }
    cout<<"\n";
    for(int i=0;i<n;i++)
    {
        cout<<(i+1)<<"-->";
        for(auto it=graph[i].begin();it!=graph[i].end();it++)
        {
            cout<<(*it)<<"-->";
        }
        cout<<"\n";
    }
}