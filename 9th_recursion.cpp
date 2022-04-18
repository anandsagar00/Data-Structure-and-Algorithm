//recursion
//print a numbers in reverse order
#include<bits/stdc++.h>
using namespace std;

void tail_recur(int n)
{
    if(n>0)
    {
        cout<<n<<" ";
        tail_recur(n-1);
    }
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    tail_recur(n);
}