/*
Implement upper Triangular Matrix using row major implementation

1 2 3 4 5
0 2 3 4 5
0 0 3 4 5
0 0 0 4 5
0 0 0 0 5

*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the dimension of matrix : ";
    cin>>n;
    //we will require a single dim array of size n*(n+1)/2 to store all the non-zero elements

    int size=n*(n+1)/2;
    int arr[size];

    //for accessing any element at any (row,col) (i,j) we will have to convert that (i,j)into index of SDA

    /*
    we will need to convert the row and cols of matrix into the index of SDA to access as well as store non-zero elements

    index=(size-((n-(i-1))*(n-(i-1)+1)/2))+(j-i) 
    */

   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int x;
           cout<<"Enter element in [ "<<i<<","<<" "<<j<<" ] : ";
           cin>>x;
           int index=(size-((n-(i-1))*(n-(i-1)+1)/2))+(j-i);

           if(i<=j)
           arr[index]=x;
        
       }
   }
   cout<<endl;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int index=(size-((n-(i-1))*(n-(i-1)+1)/2))+(j-i);
           if(i<=j)
           cout<<arr[index]<<" ";
           else
           cout<<"0 ";
       }
       cout<<endl;
   }

}