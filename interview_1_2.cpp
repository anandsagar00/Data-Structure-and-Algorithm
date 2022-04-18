//problem 1 of 2
#include<iostream>
#include<math.h>
using namespace std;
int checkPrime(int n)
{
    if(n==1)
    return 0;
    else if(n==2 || n==3)
    return 1;
    else
    {
        int c=0;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            return 0;
        }
        return 1;
    }
}
int cd(int n)
{
     int dig=0;
    int cn=n;
    while(cn>0)
    {
        dig++;
        cn/=10;
    }
    return dig;
}
int sumPower(int n)
{
   
    //cout<<"Digit : "<<dig;
    int dig=cd(n);
    int cn=n;
    int sum=0;
    while(cn>0)
    {
        sum=sum+(pow(cn%10,dig));
        cn/=10;
    }
    return sum;
}
int main()
{
    int n;
    cin>>n;
    int c=0;
    for(int i=1;i<=n;i++)
    {
        int sp=sumPower(i);
        if(checkPrime(sp) && (cd(i)==cd(sp)))
        c++;
    }
    cout<<c<<endl;
}