/*
print all subsequences of a string
I/P = "ABC"
0/P : "","A","B","C","AB","BC","AC","ABC"
*/

#include<iostream>
using namespace std;

//this function returns the length of the array which stores all the subsequences

int subsequences(string input,string output[])
{
    if(input.size()==0)
    {
        output[0]="";
        return 1;
    }
    int smalloutput=subsequences(input.substr(1),output);
    for(int i=0;i<smalloutput;i++)
    {
        output[smalloutput+i]=output[i];
        output[i]=input[0]+output[i];
    }
    return 2*smalloutput;
}
int main()
{
    string input;
    cout<<"ENTER THE STRING : ";
    cin>>input;
    string *output=new string[1000];
    cout<<"SUBSEQUENCES OF "<<input<<" ARE :\n";
    int count=subsequences(input,output);
    for(int i=0;i<count;i++)
    cout<<output[i]<<endl;
}