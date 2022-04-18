//Problem Statement :  https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// this code describes the memosesed recursive version and I have write it's other two solutions where I will be showing the complete recursive version 
// as well as the top-down approach using no recursion

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
int knapsack(int wt[],int value[],int n,int w,int **dp)
{
    if(w==0 || n==0)
    return 0;
    else if(dp[n][w]!=-1)
    return dp[n][w];
    else
    {
        if(wt[n-1]<=w)
        {
            dp[n][w]=max(value[n-1]+knapsack(wt,value,n-1,w-wt[n-1],dp),knapsack(wt,value,n-1,w,dp));
            return dp[n][w];
        }
        else
        {
            dp[n][w]=knapsack(wt,value,n-1,w,dp);
            return dp[n][w];
        }
    }
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
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[w+1];
        for(int j=0;j<w+1;j++)
        dp[i][j]=-1;
    }
    cout<<"\nTotal Profit is : "<<knapsack(wt,value,n,w,dp);
}

