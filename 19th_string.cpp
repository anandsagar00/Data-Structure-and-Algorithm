// 3) Write a Program to Remove all Characters in a String Except
// Alphabets.
// Example:
// Enter a string: p2'r"o@gram84iz./
// Output String: programiz
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string :\n";
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
        if((s[i]>=65 && s[i]<=90) || (s[i]>=97 && s[i]<=122))
        cout<<s[i];
    }
}