//given a string find its length recursively

#include<iostream>
using namespace std;

int length(char arr[])
{
    if(arr[0]=='\0')
    return 0;
    else
    return 1+length(arr+1);
}
int main()
{
    cout<<"Enter the string : ";
    char str[100];
    cin>>str;
    cout<<"Length of string is : "<<length(str);
}