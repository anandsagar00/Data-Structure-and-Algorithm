/*
Problem Statement: Replace pi (recursive)
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p
*/

//this solution does not use 100% recursion

#include<iostream>
#include<string.h>
using namespace std;
char *replaced_str=new char[100];
int j=0;
void replace_pi(char arr[],int n)
{
    if(n<=1)
    {
        replaced_str[j++]=arr[0];
        return;
    }
    if(arr[0]=='p' && arr[1]=='i')
    {
        replaced_str[j++]='3';
        replaced_str[j++]='.';
        replaced_str[j++]='1';
        replaced_str[j++]='4';
        replace_pi(arr+2,n-2);
    }
    else
    {
        replaced_str[j++]=arr[0];
        replace_pi(arr+1,n-1);
    }
}
int main()
{
    char str[100];
    cout<<"Enter the string : ";
    cin>>str;
    replace_pi(str,strlen(str));
    cout<<"\nNew string is : ";
    replaced_str[j++]='\0';
    cout<<replaced_str;
}