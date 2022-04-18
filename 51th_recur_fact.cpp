#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==1)
    return 1;
    else
    return fact(n-1)*n;
}

int main()
{
    int n;
    cout<<"Enter the value of n : ";
    cin>>n;
    cout<<"Factorial of "<<n<<" is : "<<fact(n);
}