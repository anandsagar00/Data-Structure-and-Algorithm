// Coding Problem
// Problem Statement: Check number recursively
// Problem Level: EASY
// Problem Description:
// Given an array of length N and an integer x, you need to find if x is present in the array or not. Return true or false.
// Do this recursively.
// Input Format :
// Line 1 : An Integer N i.e. size of array
// Line 2 : N integers which are elements of the array, separated by spaces
// Line 3 : Integer x

// Output Format :
// 'true' or 'false'

// Constraints :
// 1 <= N <= 10^3

// Sample Input 1 :
// 3
// 9 8 10
// 8

// Sample Output 1 :
// true

// Sample Input 2 :
// 3
// 9 8 10
// 2

// Sample Output 2 :
// false

#include<bits/stdc++.h>
using namespace std;

bool checkPresent(int arr[],int n,int key)
{
    if(arr[0]==key)
    return true;
    if(n==0)
    return false;
    return checkPresent(arr+1,n-1,key);
}

int main()
{
    int n;
    cout<<"Enter number of elements in array : \n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : \n";
    for(int i=0;i<n;i++)
    {
        cout<<" : ";

        cin>>arr[i];
        cout<<endl;
    }
    int key;
    cout<<"Enter key to search : ";
    cin>>key;
    if(checkPresent(arr,n,key))
    cout<<"\nKey is present in array.";
    else
    cout<<"\nKey is not present in array.";
}