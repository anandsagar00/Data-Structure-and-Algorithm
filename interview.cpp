//problem 2
#include<iostream>
using namespace std;
int main()
{
    int n1,n2;
    cin>>n1>>n2;
    int num1,num2;
    if(n1>n2)
    {
        num2=n1;
        num1=n2;
    }
    else
    {
        num2=n2;
        num1=n1;
    }
    int c=0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        if(arr[i]>=num1 && arr[i]<=num2)
        c++;
    }
    cout<<c;

}