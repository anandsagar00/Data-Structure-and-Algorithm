/*
Given an integer N, count and return the number of zeros that are present in the given integer using recursion.
Input Format :
Integer N

Output Format :
Number of zeros in N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
10204

Sample Output 1 :
2

Sample Input 2 :
708000

Sample Output 2 :
4
*/
#include<iostream>
using namespace std;

int countZeros(int n)
{
    if(n==0)
    return 0;
    else
    {
        if(n%10==0)
        return 1+countZeros(n/10);
        else
        return countZeros(n/10);
    }
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Total Zeros = "<<countZeros(n);
}