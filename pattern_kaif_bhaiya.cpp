#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter value of n : ";
    cin>>n;
    cout<<endl;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=i;j++)
        cout<<j<<" ";
        cout<<endl;
    }
    for(int i=n-1;i>=1;i--)
    {
        for(int j=1;j<=i;j++)
        cout<<j<<" ";
        cout<<endl;
    }
}