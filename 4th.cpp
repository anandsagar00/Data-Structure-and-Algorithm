//check if array is sorted or not

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
    int flag=1;
    if(n==1)
    cout<<"Sorted\n";
    else
    {
        for(int i=0;i<n-1;i++)
        {
            if(arr[i+1]<arr[i])
            {
                flag=0;
                break;
            }
        }
    }
    if(!flag)
    {
        cout<<"Not-Sorted\n";
    }
    else
    cout<<"Sorted\n";
}