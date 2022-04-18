//Problem Statement :  https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// this code describes the top-down version and I have write it's other two solutions where I will be showing the complete recursive version 
// as well as the memosised version

//I will not be displaying any prompt throughout this code

#include<iostream>
using namespace std;

int max(int a,int b)
{
    if(a>b)
    return a;
    else 
    return b;
}

int knapsack(int wt[],int value[],int n,int w)
{
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[w+1];
        for(int j=0;j<w+1;j++)
        dp[i][j]=0;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=0;j<w+1;j++)
        {
            if(wt[i-1]<=j)
            {
                dp[i][j]=max(value[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    return dp[n][w];
}
int main()
{
    int n;
    int w;
    cin>>n;
    cin>>w;
    int wt[n];
    int value[n];
    for(int i=0;i<n;i++)
    cin>>value[i];
    for(int i=0;i<n;i++)
    cin>>wt[i];
    cout<<"\nTotal Profit is : "<<knapsack(wt,value,n,w);
}