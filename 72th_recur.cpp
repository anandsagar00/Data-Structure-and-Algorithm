//check array is sorted or not
#include<iostream>
using namespace std;
bool checksorted(int arr[],int n)
{
    if(n==0 || n==1)
    return true;
    else
    {
        if(arr[0]>arr[1])
        return false;
        bool isSorted=checksorted(arr+1,n-1);
        return isSorted;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array.\n:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cout<<":";
    }
    if(checksorted(arr,n))
    cout<<"\nSORTED.";
    else
    cout<<"NOT-SORTED.";
}