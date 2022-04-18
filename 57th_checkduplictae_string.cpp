//in this code I have tried to print all the duplicate letters in the string
//usinf bit masking and merging

#include<iostream>
using namespace std;

int main()
{
    string s;
    cout<<"Enter the word (all lower cases only) : ";
    cin>>s;
    cout<<"\n";
    // we need to create room for atleast 26 bits as there are 26 letters 
    //so we will use a data type which provides us with 26 or more bytes i.e. int 

    int h=0;//we will use this integer to set its bit on whenever a letter is encountered

    for(int i=0;i<s.length();i++)
    {
        char ch=s.at(i);
        int x=ch-97;/*since we will require only 26 letters/bits so we are subtracting the ascii value of 'a' so that we can manage 
        to store all letters as they are ranging from 97-122*/

        int t=1;//we will use this temporary variable t to shift its bits by x bits to the left and we will merge and mask accordingly
        
        //here we are setting the xth bit on in the variable t
        
        t=t<<x;

        //here we are checking if the bit is off then on it other wise print it
        if((h&t)==0)
        {
            //if bit is off then we are turning it on
            h=(h|t);
        }
        else
        cout<<ch<<" ";
    }

}