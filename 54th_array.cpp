//find duplicates in a sorted array without using a hash table

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter size : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in array : \n";
    for(int i=0;i<n;i++)
    {
        cout<<": ";
        cin>>arr[i];
        cout<<"\n";
    }
    int last_duplicate=arr[0]-1; //to store the last duplicate element we found in the array
    //as of now I have initialised it with a random value which is not there in the array

    for(int i=0;i<n-1;i++)
    {
        if(arr[i]==arr[i+1] && arr[i]!=last_duplicate)
        {
            cout<<arr[i]<<" ";
            last_duplicate=arr[i];
        }
    }

}