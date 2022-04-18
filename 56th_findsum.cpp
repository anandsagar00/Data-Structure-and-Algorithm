//find the pair with a given sum K in the inputted array.

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter total number of elements in array : ";
    cin>>n;
    int arr[n];
    int mx=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>mx)
        mx=arr[i];
    }
    int k;
    cout<<"Enter the sum : ";
    cin>>k;
    int hash[mx+1];
    hash[0]=0;
    //now the magic begins

    for(int i=0;i<n;i++)
    {
        hash[arr[i]]=1;
        int sumleft=k-arr[i];
        if(hash[sumleft]==1)
        cout<<arr[i]<<" + "<<k-arr[i]<<" = "<<k<<endl;
    }
}