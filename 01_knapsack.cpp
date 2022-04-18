//Problem Statement :  https://practice.geeksforgeeks.org/problems/0-1-knapsack-problem0945/1

// this code describes the recursive version and I have written it's other two solutions where I will be showing the memozized version 
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

int knapsack(int wt[],int value[],int n,int w)
{
    //if the weight of sack is 0 or if the total items are 0 the there is no profit
    if(n==0 || w==0)
    return 0;
    else
    {
        if(wt[n-1]<=w)
        {
            //if weight of element is less then the capacity of knapsack then there are two cases
            //if we include that element and  then if we don't include the element
            //we will return the maximum profit out of the two cases

            return max(value[n-1]+knapsack(wt,value,n-1,w-wt[n-1]),knapsack(wt,value,n-1,w));
        }
        else
        return knapsack(wt,value,n-1,w);
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
    cout<<"\nTotal Profit is : "<<knapsack(wt,value,n,w);
}