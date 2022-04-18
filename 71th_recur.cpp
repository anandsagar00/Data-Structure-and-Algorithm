//count digits in a number
#include<iostream>
using namespace std;

int digits(int n)
{
    if(n<=0)
    return 0;
    else
    return 1+digits(n/10);
}

int main()
{
    cout<<"Enter the number : ";
    int n;
    cin>>n;
    cout<<"Number of digits in the number are : "<<digits(n);
}