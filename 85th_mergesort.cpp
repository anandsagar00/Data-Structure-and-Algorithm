//I am very happy as withot seeing the code from anywhere it worked in its first attempt only (emotional🥳🥺)

/*
Sort an array A using Merge Sort.
Change in the input array itself. So no need to return or print anything.
Input format :
Line 1 : Integer n i.e. Array size
Line 2 : Array elements (separated by space)

Output format :
Array elements in increasing order (separated by space)

Constraints :
1 <= n <= 10^3

Sample Input 1 :
6 
2 6 8 5 4 3

Sample Output 1 :
2 3 4 5 6 8

Sample Input 2 :
5
2 1 5 2 3

Sample Output 2 :
1 2 2 3 5
*/

#include<iostream>
using namespace std;

//this function merges the first half of array with other half using an auxiliary array

void mergeArrays(int arr[],int start,int end)
{
    int i=start;
    int mid=(start+end)/2;
    int j=mid+1;
    int k=0;
    int size=(end-start+1);
    int arr1[size];
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        {
            arr1[k++]=arr[i++];
        }
        else
        arr1[k++]=arr[j++];
    }
    while(i<=mid)
    arr1[k++]=arr[i++];
    while(j<=end)
    arr1[k++]=arr[j++];
    for(int l=0;l<size;l++)
    arr[start++]=arr1[l];

}
void mergesort(int  arr[],int start,int end)//start and end are start and end Index
{
    if(end<=start)
    return;
    if(arr[0]>arr[1])
    {
        int temp=arr[0];
        arr[0]=arr[1];
        arr[1]=temp;
        int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        mergeArrays(arr,start,end);
    }
    else
    {
         int mid=(start+end)/2;
        mergesort(arr,start,mid);
        mergesort(arr,mid+1,end);
        mergeArrays(arr,start,end);
    }
}
int main()
{
    int n=rand();
    // cout<<"Enter the size of array : ";
    // cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    // for(int i=0;i<n;i++)
    // {
    //     cout<<":";
    //     cin>>arr[i];
    // }
    //cout<<endl;
    mergesort(arr,0,n-1);
    //cout<<"Sorted array is : \n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<endl;

}