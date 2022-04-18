/*
Problem Level: HARD
Problem Description:
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array
and return the count of elements populated in the output array.
Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/

#include<iostream>
#include<math.h>
using namespace std;

string keys[]={"abc","def","ghi","jkl","mno","pqr","stu","vwx","yz"};

int keypad(string input,string output[])
{
    if(input.size()==1)
    {
        int keyvalue=(input[0]-48)-1;
        for(int k=0;k<keys[keyvalue].length();k++)
        {
            output[k]=keys[keyvalue][k];
        }
        
        return 3;
    }
    int smalloutput=keypad(input.substr(1),output);
    int j=0;
    int keyvalue=(input[0]-48)-1;
    for(int i=0;i<smalloutput;i++)
    {
        for(int k=0;k<keys[keyvalue].length();k++)
        {
            output[smalloutput+j]=keys[keyvalue][k]+output[i];
            j++;
        }
    }
    return pow(3,smalloutput);
}

int main()
{
    string input;
    cout<<"ENTER THE STRING : ";
    cin>>input;
    string *output=new string[1000];
    cout<<"KEYPAD VALUE OF "<<input<<" ARE :\n";
    int count=keypad(input,output);
    for(int i=0;i<=count;i++)
    cout<<output[i]<<endl;
}
