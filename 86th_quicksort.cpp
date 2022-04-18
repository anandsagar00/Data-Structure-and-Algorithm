/*
Problem Statement: Quick Sort
Problem Level: MEDIUM
Problem Description:
Sort an array A using Quick Sort.
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
1 5 2 7 3

Sample Output 2 :
1 2 3 5 7
*/

#include<iostream>
using namespace std;

int partition(int arr[],int start,int end)
{
    int x=arr[start];
    int count_smaller_than_x=0;
    for(int i=start+1;i<=end;i++)
    {
        if(arr[i]<=x)
        count_smaller_than_x=count_smaller_than_x+1;
    }
    //pushung x to correct position
    int temp=arr[start];
    arr[start]=arr[start+count_smaller_than_x];
    arr[start+count_smaller_than_x]=temp;
    //we will move move all smaller elements to left and all larger to right of x
    int i=start;
    int j=end;
    while(i<(start+count_smaller_than_x) && j>(start+count_smaller_than_x))
    {
        if(arr[i]<=x)
        {
            i++;
        }
        else if(arr[j]>x)
        {
            j--;
        }
        else
        {
            int t=arr[i];
            arr[i]=arr[j];
            arr[j]=t;
            i++;
            j--;
        }
    }
    return start+count_smaller_than_x;
}
void quicksort(int arr[],int start,int end)
{
    if(start>=end)
    return;
    int pivot_point=partition(arr,start,end);
    quicksort(arr,start,pivot_point-1);
    quicksort(arr,pivot_point+1,end);
}
int main()
{
    int n;
    cout<<"Enter the size of array : ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements : ";
    for(int i=0;i<n;i++)
    {
       arr[i]=rand()%1000;
    }
    cout<<endl;
    quicksort(arr,0,n-1);
    cout<<"Sorted array is : \n";
    for(int i=0;i<n;i++)
    cout<<arr[i]<<" ";

}