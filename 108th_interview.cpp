#include<iostream>
using namespace std;
int main()
{
    string str;
    cout<<"Enter the string : ";
    cin>>str;
    int l=str.length();
    string temp_str="";
    string max_str="";
    int max_len=0;
    int temp_len=0;
    for(int i=0;i<l;i++)
    {
        char ch=str[i];
        if(i<l-1 && ch!=str[i+1])
        temp_str+=ch;
        else
        {
            if(i==l-1)
            temp_str+=str[l-1];
            // else
            // temp_str+=ch;
            temp_len=temp_str.length();
            if(temp_len>=max_len)
            {
                max_len=temp_len;
                max_str=temp_str;
            }
            temp_str="";
            temp_len=0;
        }
    }
    cout<<"Max length is : "<<max_len<<endl;
    cout<<"Max string is : "<<max_str;
}