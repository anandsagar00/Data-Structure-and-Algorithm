//problem 1 of 3rd set
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
            return 1;
        }
        return 0;
    }
}
int sumOfPrimeFactors(int n)
{
    int c=0;
    while (n % 2 == 0)
    {
        c+=2;
        n = n/2;
    }
 
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        while (n % i == 0)
        {
            c+=i;
            n = n/i;
        }
    }

    if (n > 2)
        c+=n;
    return c;
}
int main()
{
    int n;
    cin>>n;
    cout<<sumOfPrimeFactors(n);
}