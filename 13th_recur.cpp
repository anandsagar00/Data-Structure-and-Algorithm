//to check if a given string is pallindrome or not
#include<bits/stdc++.h>
using namespace std;

int check_palindrome(string s,int n,int curr=0)//n is length of string and curr is the current index
{
    if(curr<n-1)
    {
        if(s[curr]!=s[n-1])
        return 0;
        else
        check_palindrome(s,n-1,curr+1);
    }
    return 1;
}
int main()
{
    string s;
    cout<<"Enter the string : ";
    cin>>s;
    if(check_palindrome(s,s.length()))
    {
        cout<<"\nPallindrome";
    }
    else
    cout<<"Non-Pallindrome\n";
}