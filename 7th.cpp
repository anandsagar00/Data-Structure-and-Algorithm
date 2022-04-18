/*to remove elements from a sorted array in O(n) time and O(1) space i.e without copying elements
to a new array */
//discussed in gfg

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter numeber of elements in an array :\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<": ";
        cin>>arr[i];
    }
    int last_unique_element=arr[0];/*this will store the last element which was unique and was sent at
                             the beginning of the array (first element is always unique)*/
    
    int total=1;//to store the count of total unique elements
    for(int i=1;i<n;i++)
    {
        if(arr[i]!=last_unique_element)
        {
            arr[total]=arr[i];
            last_unique_element=arr[i];
            total+=1;
        }
    }
    cout<<"Array elements after removing duplicates are : \n";
    for(int i=0;i<total;i++)
    cout<<arr[i]<<" ";
}