//problem 2 of 2
#include<iostream>
using namespace std;
int main()
{
    int p;
    cin>>p;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    cin>>arr[i];
    int flag=0;
    int a,b;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i]*arr[j]==p)
            {
                a=arr[i];
                b=arr[j];
                flag=1;
                break;
            }
        }
    }
    if(flag==0)
    cout<<"-1"<<endl;
    else
    {
        cout<<a<<" "<<b<<endl;
    }
}