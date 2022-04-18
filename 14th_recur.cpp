//find the sum of digits using recursion
#include<bits/stdc++.h>
using namespace std;

int sod(int n)//to return sum of digits of a number
{
    static int sum=0;
    if(n>0)
    {
        sum=sum+(n%10);
        return sod(n/10);
    }
    return sum;
}
int sod1(int n)
{
    if(n==0)
    return 0;
    return (n%10)+sod1(n/10);
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Sum of digits of "<<n<<" is : "<<sod(n)<<endl;
    cout<<"Sum of digits of "<<n<<" is : "<<sod1(n);
}