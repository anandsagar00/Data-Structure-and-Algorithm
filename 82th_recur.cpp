/*
Problem Statement: Remove X
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:


*/

//this code of mine doesn't use 100% recursion

#include<iostream>
using namespace std;
#include<string.h>
void replaceX(char arr[],int n)
{
    if(n==1 && arr[0]=='x')
    {
        arr[0]='\0';
    }
    if(n<=1)
    return;
    
    else
    {  
        if(arr[0]=='x')
        {
            int i=0;
            for( ;i<n-1;i++)
            arr[i]=arr[i+1];
            arr[i++]='\0';
            replaceX(arr,n-1);
        }
        else
        {
            replaceX(arr+1,n-1);
        }
    }
}
int main()
{
    char str[100];
    cout<<"Please ENTER your string : ";
    cin>>str;
    replaceX(str,strlen(str));
    cout<<"Your New String is : "<<str;
}