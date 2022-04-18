//remove duplicates from an array
// (Method 2 at 7th.cpp file)
//I will use another array as hash to count the frequency
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter numeber of elements in an array :\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array :"<<endl;
    int max_element=INT_MIN;
    for(int i=0;i<n;i++)
    {
        cout<<": ";
        cin>>arr[i];
        if(arr[i]>max_element)
        max_element=arr[i];
    }

    int *hash=new int[max_element];//create an array in heap
    hash[0]=0;//creates an array with total size as one more than that of max element of array
    //I will use this array to count the frequency

    for(int i=0;i<n;i++)
    {
        hash[arr[i]]+=1;
    }
    cout<<"Array elements after removing duplicates are : \n";
    for(int i=0;i<=max_element;i++)
    {
        if(hash[i]>0)
        cout<<i<<" ";
    }
}