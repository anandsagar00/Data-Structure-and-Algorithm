//finding nth fibonacci using recursion
//0, 1, 1, 2, 3, 5, 8, 13, 21, 34, 55, 89, 144
#include<bits/stdc++.h>
using namespace std;
int fib(int n,int ft=-1,int st=1)//ft is 1st term,st is second term and ct is current term
{
    static int n1=1;
    if(n1<=n)
    {
        n1=n1+1;
        cout<<"ft : "<<ft<<" st : "<<st<<" ct : "<<st+ft<<endl;
        return fib(n,st,st+ft);//(we know ct=ft+st, but for next iteration ct becomes the second term and st terms becomes ft)
    }
    return st+ft;
}
int main()
{
    int n;
    cout<<"Enter number : ";
    cin>>n;
    
    cout<<n<<"th fibonacci number is \n"<<fib(n);
    
}