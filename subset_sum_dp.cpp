//to find whether a subset with a given sum is present or not

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter the length of the array : ";
    cin>>n;
    int arr[n];
    cout<<"\nEnter the array elements :\n";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int sum;
    cout<<"\nENTER THE SUM : \n";
    cin>>sum;
    bool dp[n+1][sum+1];

    //pre-processing the array
    //i.e if the length of the array is 0 then whether a given sum is present or not
    //and if the subset with sum 0 is present or not for a given length of array

    for(int j=0;j<sum;j++)
    {
        dp[0][j]=false;
    }

    for(int i=0;i<n;i++)
    {
        dp[i][0]=true;
    }

    for(int i=1;i<n+1;i++)
    {
        for(int j=1;j<sum+1;j++)
        {
            //J is denoting sum and I is denoting n

            if(arr[i-1]<=j)
            {
                dp[i][j]=(dp[i-1][j-arr[i-1]] || dp[i-1][j]);
            }
            else
            dp[i][j]=dp[i-1][j];
        }
    }
    if(dp[n][sum])
    cout<<"\nPresent";
    else
    cout<<"\nNOT-Present";
}