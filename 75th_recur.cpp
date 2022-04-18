/*
Given an array of length N and an integer x, you need to find all the indexes where x is present in the input array.
Save all the indexes in an array (in increasing order).
Do this recursively. Indexing in the array starts from 0.
Input Format :
Line 1 : An Integer N i.e. size of array
Line 2 : N integers which are elements of the array, separated by spaces
Line 3 : Integer x

Output Format :
indexes where x is present in the array (separated by space)

Constraints :
1 <= N <= 10^3

Sample Input :
5
9 8 10 8 8
8

Sample Output :
1 3 4
*/

//first of all I will try to print all the indices but in my next code I will store the indices in an array

#include<iostream>
using namespace std;
void printIndices(int arr[],int n,int key,int ind=0)
{
    if(ind==n)
    return;
    if(arr[ind]==key)
    cout<<ind<<" ";
    printIndices(arr,n,key,ind+1);
}
int main()
{
    int n;
    cout<<"Enter the number of elements : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array.\n:";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        cout<<":";
    }
    int key;
    cout<<"Enter key to search : ";
    cin>>key;
    cout<<"All indices of "<<key<<" are : "<<endl;
    printIndices(arr,n,key);
}