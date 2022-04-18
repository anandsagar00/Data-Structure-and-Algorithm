//array operations 
//largest element smallest element
//second largest and second smallest

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
    //most naive approach can be sort and print 
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int t=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=t;
            }
        }
    }
    if(n>=4)
    {
        cout<<"Largest element : "<<arr[n-1]<<endl;
        cout<<"Second largest element : "<<arr[n-2]<<endl;
        cout<<"Smallest element : "<<arr[0]<<endl;
        cout<<"Second smallest element : "<<arr[1]<<endl;
    }
    else if(n==1)//checking for all the corner cases 
    {
        cout<<"Largest element : "<<arr[0]<<endl;
        cout<<"Second largest element : "<<arr[0]<<endl;
        cout<<"Smallest element : "<<arr[0]<<endl;
        cout<<"Second smallest element : "<<arr[0]<<endl;
    }
    else if(n==2)
    {
        cout<<"Largest element : "<<arr[1]<<endl;
        cout<<"Second largest element : "<<arr[0]<<endl;
        cout<<"Smallest element : "<<arr[0]<<endl;
        cout<<"Second smallest element : "<<arr[1]<<endl;
    }
    else if(n==3)
    {
        cout<<"Largest element : "<<arr[2]<<endl;
        cout<<"Second largest element : "<<arr[1]<<endl;
        cout<<"Smallest element : "<<arr[0]<<endl;
        cout<<"Second smallest element : "<<arr[1]<<endl;
    }
}