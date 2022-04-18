//factorial using recursion
#include<bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if(n>1)
    {
        return fact(n-1)*n;
    }
    return 1;
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"\nFactorial of "<<n<<" is : "<<fact(n);
}