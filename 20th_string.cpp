// Write a C++ program to find the largest word in a given
// String.
// Example:
// Sample Input: C++ is a general-purpose programming language.
// Sample Output: programming
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout<<"Enter the string :\n";
    getline(cin,s);
    string max="";
    string temp="";
    for(int i=0;i<s.length();i++)
    {

        if(s[i]!=' ' && i != (s.length()-1))
            temp=temp+s[i];
        else
        {
            if(temp.length()>max.length())
            {
                max=temp;
            }
            temp="";
        }
    }
    cout<<"\nBiggest word is : "<<max;
}