//implement binary search using loops
#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[],int n,int key)
{
    int high=n-1;
    int low=0;
    int mid=(low+high)/2;
    while(low<high)
    {
        if(arr[mid]==key)
        return 1;
        else if(arr[mid]<key)
        {
            low=mid+1;
        }
        else if(arr[mid]>key)
        {
            high=mid-1;
        }
        mid=(low+high)/2;
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
    if(binary_search(arr,n,key))
    cout<<"Key : "<<key<<" is present.\n";
    else
    cout<<"Key : "<<key<<" is not present.\n";
}