//implement binary search using recursion
#include <bits/stdc++.h>
using namespace std;
int binary_search(int arr[],int key,int high,int low=0)
{
    int mid=(high+low)/2;
    if(low<high)
    {
        if(arr[mid]==key)
        return 1;
        else if(arr[mid]<key)
        return(arr,key,high,mid+1);
        else if(arr[mid]>key)
        return(arr,key,mid-1,low);
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter number of elements in the array : ";
    cin>>n;
    cout<<"Enter elements in the array in a sorted manner : \n";
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int key;
    cout<<"Enter key to search : ";
    cin>>key;
    if(binary_search(arr,key,n-1))
    cout<<"Key : "<<key<<" is present.\n";
    else
    cout<<"Key : "<<key<<" is not present.\n";
}