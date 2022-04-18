//reverse an array
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
    int low=0;//to store the index of first element
    int high=n-1;//to store the index of last element
    while(low<high)
    {
        int temp=arr[low];
        arr[low]=arr[high];
        arr[high]=temp;
        low++;
        high--;
    }
    cout<<"The reversed array is :\n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";
}