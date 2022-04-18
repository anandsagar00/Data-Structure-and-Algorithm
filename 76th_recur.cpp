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

//A very similar approach of mine with a detailed explanation :
//      https://www.youtube.com/watch?v=bQkwHBaNioE

#include<iostream>
using namespace std;

int sizeOfArray=0;
int *allIndices(int arr[],int n,int key,int index=0,int found_so_far=0)
{
    if(n==0)
    {
        int *ptr=new int[found_so_far];
        sizeOfArray=found_so_far;
        return ptr;
    }
    if(arr[0]==key)
    {
        int *p=allIndices(arr+1,n-1,key,index+1,found_so_far+1);
        p[found_so_far]=index;
        return p;
    }
    else
    {
        int *p=allIndices(arr+1,n-1,key,index+1,found_so_far);
        return p;
    }

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
    int *indices=allIndices(arr,n,key);
    for(int i=0;i<sizeOfArray;i++)
    cout<<indices[i]<<" ";
}