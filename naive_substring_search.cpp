//find a substring is present in a given string or not using brut-force/naive algorithm

#include <iostream>
#include<string>
using namespace std;

int main()
{
    string str;
    string sub;
    cout<<"\nEnter the string : ";
    getline(cin,str);
    cout<<"\nEnter the substring/pattern you want to search : "<<endl;
    cin>>sub;
    int l=str.length();
    int l2=sub.length();
    int flag=0;
    int index=-1;
    for(int i=0;i<l-l2+1;i++)
    {
        int count=0;
        if(str[i]!=sub[0])
        continue;
        else
        {
            int i1=i;
            for(int j=0;j<l2;j++)
            {
                if(str[i1++]==sub[j])
                count++;
            }
            if(count==l2)
            {
                flag=1;
                index=i;
            }
        }
    }
    if(flag)
    cout<<"\nPattern is present in the string at index : "<<index<<endl;
    else
    cout<<"\nPattern not present in the given string."<<endl;
}