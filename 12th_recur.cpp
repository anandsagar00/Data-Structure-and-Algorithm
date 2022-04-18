//natural number sum using recursion
#include<bits/stdc++.h>
using namespace std;
int sum(int n)
{
    if(n!=0)
    {
        return n+sum(n-1);
    }
    return 0;
}
int main()
{
    int n;
    cout<<"Enter number : ";
    cin>>n;
    cout<<"Sum of "<<n<<" natural number is : "<<sum(n);
}