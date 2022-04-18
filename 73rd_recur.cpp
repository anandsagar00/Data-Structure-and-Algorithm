//check if a number is present in the array or not and return its index of first occurence if not present then return -1
#include<iostream>
using namespace std;

int indexOf(int arr[],int n,int key)
{
    if(n<=0)
    return -1;
    if(arr[0]==key)
    return 0;
    else
    {
        int index=indexOf(arr+1,n-1,key);
        if(index==-1)
        return index;
        else
        return 1+index;
        // if(indexOf(arr+1,n-1,key)!=-1)
        // {
        //     int index=1+indexOf(arr+1,n-1,key);
        //     return index;
        // }
        // else
        // return -1;
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
    int key;
    cout<<"Enter key to search : ";
    cin>>key;
    cout<<"\nIndex of Key is : "<<indexOf(arr,n,key);
}