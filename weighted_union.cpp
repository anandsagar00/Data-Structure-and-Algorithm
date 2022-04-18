/*
We will be using 2 arrays one to store size of each component and one to store the root of each set
then we will add a smaller tree as a child onto a larger tree
*/

/*
We can further optimise this approach by making all the new component to point directly to the actual root
this technique is called as path compression 
*/

#include<iostream>
#include<vector>
#include<iterator>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;

void weightedUnion(int *disjointset,int *size,int a,int b)
{
    //the disjoint set array stores the different sets of trees formed 
    //alag alag jo components banega uska information store karta hai

    if(disjointset[a]==disjointset[b]) return;

    else if (size[a]>=size[b])
    {
        size[a]+=size[b];
        disjointset[b]=a;
    }
    else 
    {
        size[b]+=size[a];
        disjointset[a]=b;
    }
}

int root(int *disjointset,int a)
{
    while(disjointset[a]!=a)
    a=disjointset[a];
    return a;
}

bool connected(int *disjoinset,int a,int b)
{
    return root(disjoinset,a)==root(disjoinset,b);
}

int main()
{
    //taking input from user

    //total number of objects
    cout<<"Total count of nodes : ";
    int n;
    cin>>n;

    int *disjointset=new int[n];
    int *size=new int[n];
    for(int i=0;i<n;i++)
    {
        disjointset[i]=i;
        size[i]=1;
    }

    while(true)
    {
        int ch;
        cout<<"Press 1 to union\nPress 2 to find connected\nPress 3 to exit\n";
        cin>>ch;
        if(ch==3) break;
        else if(ch==1)
        {
            int a,b;
            // cout<<"Press 2 nums to union.";
            cin>>a>>b;
            weightedUnion(disjointset,size,a,b);
        }
        else
        {
            int a,b;
            // cout<<"Press 2 nums to find connected.";
            cin>>a>>b;
            if(connected(disjointset,a,b))
            cout<<"Connected\n";
            else
            {
                cout<<"Not connected\n";
            }
        }

    }
}