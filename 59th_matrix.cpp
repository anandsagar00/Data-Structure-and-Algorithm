/*
implement lower triangular matrix using row-major formula
and by using a single dim array to reduce space complexity
as most of the elements of lower triangular matrix are 0
*/

//In my case row and cols start from 1 rather than 0

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the dimension of matrix : ";
    cin>>n;

    //total space we require to fill a non-zero element in a Lower Triangular Matrix is n*(n+1)/2
    //If you didn't get it then plot a Lower Triangular Matrix yourself and then see

    int size=n*(n+1)/2;
    int arr[size];//single dim array to store non 0 elements

    /*point to be noted
    Cols---->
row
 |   1 0 0 0 0
 |   2 3 0 0 0
 |   4 5 6 0 0
 *   7 8 9 5 0
     1 2 3 4 5 

    If we want to access the matrix element then 
    when i>=j then,
    matrix[i][j]=arr[index]
    where index is 

    index = ((i-1)*(i-1+1)/2))+(j-1)  =   (i*(i-1)/2)+(j-1)
    otherwise 0
    */

   cout<<"Enter elemets : ";
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int x;
           cout<<"Enter element in [ "<<i<<","<<" "<<j<<" ] : ";
           cin>>x;
           int index=(i*(i-1)/2)+(j-1);
           if(i>=j)
           arr[index]=x;
       }
   }
   cout<<endl;
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=n;j++)
       {
           int index=(i*(i-1)/2)+(j-1);
           if(i>=j)
           cout<<arr[index]<<" ";
           else
           cout<<"0 ";
       }
       cout<<endl;
   }

}