//implement a diagonal matrix using a single dim array to save space
//here I have considered row and coloumn starting from 1

#include<iostream>
using namespace std;

int main()
{
    int n;
    cout<<"Enter number of rows : ";
    cin>>n;
    int arr[n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cout<<"Enter element in [ "<<i<<","<<" "<<j<<" ] : ";
            int x;
            cin>>x;
            if(i==j)
            arr[i-1]=x;
            cout<<endl;
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            cout<<arr[i-1]<<" ";
            else
            cout<<"0 ";
        }
        cout<<endl;
    }

}