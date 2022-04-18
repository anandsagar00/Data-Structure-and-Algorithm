#include<iostream>
using namespace std;

int partition(int *arr,int low,int high)
{
    int i=low,j=high;
    while(i<j)
    {
        while(arr[i]<=arr[low])
        {
            i++;
            if(i==high) break;
        }
        while(arr[j]>arr[low])
        {
            j--;
            if(j==low)
            break;
        }
        if(i>=j) break;
        swap(arr[i],arr[j]);
    }
    swap(arr[low],arr[j]);
    return j;
}

void quick_sort(int *arr,int low,int high)
{
    if(high>low)
    {
        int p=partition(arr,low,high);
        quick_sort(arr,low,p-1);
        quick_sort(arr,p+1,high);
    }
}

bool isSorted(int *arr,int n)
{
    //checks if array is sorted or not
    for(int i=0;i<n-1;i++)
    {
        if(arr[i]>arr[i+1])
        return false;
    }
    return true;
}

int main()
{
    int n=10000;
    int arr[n];//creating an array with garbage values
    quick_sort(arr,0,n-1);
    if(isSorted(arr,n))
    {
        cout<<"Sorted.\n";
    }
    else
    cout<<"Not-Sorted\n";
}