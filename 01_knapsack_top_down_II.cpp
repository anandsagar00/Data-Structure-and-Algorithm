#include<iostream>
using namespace std;

int knapsack(int weight[],int value[],int W,int n)
{
    if(n==0||W==0)
    return 0;
    else
    {
        //first if the weight of item is less than the weight that can be handled by knapsack then we may include other wise we will surely not
        if(weight[n-1]<=W)
        {
            return max(value[n-1]+knapsack(weight,value,W-value[n-1],n-1),knapsack(weight,value,W,n-1));
        }
        else
        return knapsack(weight,value,W,n-1);
    }
}

int knapsack(int weight[],int value[],int W,int n,int **dp)
{
    if(n==0 || W==0)
    {
        dp[n][W]=0;
        return 0;
    }
    else if(dp[n][W]!=-1)
    return dp[n][W];
    else
    {
        if(weight[n-1]<=W)
        {
            dp[n][W]=max(value[n-1]+knapsack(weight,value,W-weight[n-1],n-1,dp),knapsack(weight,value,W,n-1,dp));
            return dp[n][W];
        }
        else
        {
            dp[n][W]=knapsack(weight,value,W-weight[n-1],n-1,dp);
            return dp[n][W];
        }
    }
}
int knapsack_top_down(int weight[],int value[],int n,int W)
{
    int **dp=new int*[n+1];
    for(int i=0;i<n+1;i++)
    {
        dp[i]=new int[W+1];
        for(int j=0;j<W+1;j++)
        dp[i][j]=0;
    }
    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<W+1;j++)
        {
            if(weight[i-1]<=j)
            {
                //if the weight of the item is less than the weight left to tear KnapSack
                //then we will have two cases either we will include the item or discard
                dp[i][j]=max(value[i-1]+dp[i-1][j-weight[i-1]],dp[i-1][j]);
            }
            else
            {
                //straight away we will discard it
                dp[i][j]=dp[i-1][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cout<<"Enter number of items : ";
    cin>>n;
    int weight[n];
    int value[n];
    int W;
    cout<<"\nEnter total weight which the sack can handle : ";
    cin>>W;
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter price of items : ";
        cin>>value[i];
    }
    for(int i=0;i<n;i++)
    {
        cout<<"\nEnter weight : ";
        cin>>weight[i];
    }
    cout<<"\nFrom recursion : "<<knapsack(weight,value,W,n)<<endl;
    int **dp=new int*[W+1];
    for(int i=0;i<n+1;i++)
    {   dp[i]=new int[W+1];
        for(int j=0;j<W+1;j++)
        dp[i][j]=-1;
    }
    cout<<"\nFrom memosization : "<<knapsack(weight,value,W,n,dp);
    cout<<"\nFrom top-doen : "<<knapsack_top_down(weight,value,n,W);
}
/*
3
4
1 2 3
4 5 1
*/