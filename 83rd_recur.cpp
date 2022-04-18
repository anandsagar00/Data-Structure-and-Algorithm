/*
Problem Description:
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a
*/

#include<iostream>
using namespace std;
#include<string.h>
void pair_star(char arr[],int n)
{
    if(n<=1) 
    return;
    else
    {
        if(arr[0]==arr[1])
        {
            for(int i=n+1;i>=2;i--)
            arr[i]=arr[i-1];
            arr[1]='*';
            pair_star(arr+1,n+2);
        }
        else
        {
            pair_star(arr+1,n-1);
        }
    }
}
int main()
{
    char str[100];
    cout<<"Enter the string : ";
    cin>>str;
    pair_star(str,strlen(str));
    cout<<"New String is : "<<str;

}