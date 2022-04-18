// Coding Problem
// Problem Statement: Number of digits
// Problem Level: EASY
// Problem Description:
// Given the code to find out and return the number of digits present in a number recursively. But it contains few bugs, that you need to rectify such that all the test cases should pass.
// Input Format :
// Integer n

// Output Format :
// Count of digits

// Constraints :
// 1 <= n <= 10^6

// Sample Input 1 :
//  156

// Sample Output 1 :
// 3

// Sample Input 2 :
//  7

// Sample Output 2 :
// 1

#include<bits/stdc++.h>
using namespace std;

int count_digits(int n)
{
    static int count=0;
    if(n==0)
    return count;
    count=count+1;
    return count_digits(n/10);
}
int main()
{
    int n;
    cout<<"Enter the number : ";
    cin>>n;
    cout<<"Number of digits : "<<count_digits(n);
}