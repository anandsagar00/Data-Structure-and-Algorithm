// find a ^ b using recursion
/*basically 
                a^b=a*(a^(b-1))
*/
#include<bits/stdc++.h>
using namespace std;

int power(int a,int b)
{
    if(b==0)
    return 1;
    else
    return a*power(a,b-1);
}
int main()
{
    int a,b;
    cout<<"Enter the value of a and b : ";
    cin>>a>>b;
    cout<<"a raised to power b is : "<<power(a,b);
}