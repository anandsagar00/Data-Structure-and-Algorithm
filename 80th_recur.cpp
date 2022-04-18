/*
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false
*/
#include<iostream>
#include<string>
#include<string.h>
using namespace std;
bool isPallindrome(char arr[],int n)
{
    if(n<=1)
    return true;
    if(arr[0]!=arr[n-1])
    return false;
    return isPallindrome(arr+1,n-2);
}
int main()
{
    char str[100];
    cout<<"Enter the string : ";
    cin>>str;
    if(isPallindrome(str,strlen(str)))
    cout<<"PALLINDROME";
    else
    cout<<"NOT-PALLINDROME";
}