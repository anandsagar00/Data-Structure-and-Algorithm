/*
Problem Level: EASY
Problem Description:
Given two string s and t, write a function to check if s contains all characters of t (in the same order as they are in string t).
Return true or false.
Do it recursively.
E.g. : s = “abchjsgsuohhdhyrikkknddg” contains all characters of t=”coding” in the same order. So function will return true.
Input Format :
Line 1 : String s
Line 2 : String t

Output Format :
true or false

Sample Input 1 :
abchjsgsuohhdhyrikkknddg
coding

Sample Output 1 :
true

Sample Input 2 :
abcde
aeb

Sample Output 2 :
false
*/
#include<iostream>
using namespace std;

bool check_string(string str,string check)
{
    int j=0;
    for(int i=0;i<str.length();i++)
    {
        if(j!=check.length() && str[i]==check[j])
        j++;
        if(j==check.length())
        return true;
    }
    return false;
}
int main()
{
    string str,check;
    cin>>str>>check;
    cout<<check_string(str,check);
}