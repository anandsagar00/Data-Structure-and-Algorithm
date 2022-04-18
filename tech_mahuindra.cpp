#include<iostream>
using namespace std;
bool checkIsAP(int arr[], int n)
{
    if (n == 1)
        return true;
 
    double d = arr[1] - arr[0];
 
    for (int i = 2; i < n; i++) {
        if (arr[i] - arr[i - 1] != d) {
            return false;
        }
    }
 
    return true;
}
bool checkIsGP(int arr[], int n)
{
    
    if (n == 1)
        return true;
 
    double r = arr[1] / arr[0];
 
    for (int i = 2; i < n; i++) {
        if (arr[i] / arr[i - 1] != r)
            return false;
    }
 
    return true;
}
bool checkIsFibonacci(int arr[], int n)
{
    if (n == 1 || n == 2)
        return true;
 
    for (int i = 2; i < n; i++)
        if ((arr[i - 1] + arr[i - 2])
            != arr[i])
            return false;
 
    return true;
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    if(n>=2)
    {
    if(checkIsAP(arr,n))
    {
        int cd=arr[1]-arr[0];
        cout<<arr[n-1]+cd;
    }
    else if(checkIsGP(arr,n))
    {
        int cr=arr[1]/arr[0];
        cout<<arr[n-1]*cr;
    }
    else if (checkIsFibonacci(arr,n))
    {
       cout<<arr[n-1]+arr[n-2];
    }
    else
    cout<<-999;
    }
    else
    {
        cout<<-999;
    }
}