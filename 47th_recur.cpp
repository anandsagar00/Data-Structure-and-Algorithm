// Problem Statement: Replace character recursively
// Problem Level: EASY
// Problem Description:
// Given an input string S and two characters c1 and c2, you need to replace every occurrence of character c1 with character c2 in the given string.
// Do this recursively.
// Input Format :
// Line 1 : Input String S
// Line 2 : Character c1 and c2 (separated by space)

// Output Format :
// Updated string

// Constraints :
// 1 <= Length of String S <= 10^6

// Sample Input :
// abacd
// a x

// Sample Output :
// xbxcd

#include<bits/stdc++.h>
using namespace std;
void replaceChar(char str[],int n,char ch1,char ch2)
{
    if(str[0]==ch1)
    str[0]=ch2;
    if(n==0)
    return;
    replaceChar(str+1,n-1,ch1,ch2);

}
int main()
{
    char str[50];
    cout<<"Enter the string : ";
    cin>>str;
    char ch1,ch2;
    cout<<"\nEnter char you want to replace : ";
    cin>>ch1;
    cout<<"Enter char you want to replace with : ";
    cin>>ch2;
    replaceChar(str,strlen(str),ch1,ch2);
    cout<<str;

}