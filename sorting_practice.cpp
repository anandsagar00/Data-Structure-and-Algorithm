#include<iostream>
#include<time.h>
using namespace std;

void swap(int &a,int &b)
{
    int temp=a;
    a=b;
    b=temp;
}
void selection_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        int select=arr[i+1];
        int ind=i+1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<select)
            {
                select=arr[j];
                ind=j;
            }
        }
        swap(arr[i],arr[ind]);
    }
}
void bubble_sort(int arr[],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            swap(arr[j],arr[j+1]);
        }
    }
}
void merge_arrays(int arr[],int start,int mid,int end)
{
    int x=end-start+1;
    int *arr1=new int[x];
    int k=0;
    int i=start;
    int j=mid+1;
    while(i<=mid && j<=end)
    {
        if(arr[i]<=arr[j])
        arr1[k++]=arr[i++];
        else
        arr1[k++]=arr[j++];
    }
    while(i<=mid)
    arr1[k++]=arr[i++];
    while(j<=end)
    arr1[k++]=arr[j++];
    for(int l=0;l<x;l++)
    {
        arr[start++]=arr1[l];
    }
}
void merge_sort(int arr[],int start,int end,int n)
{
    if(start>=end)
    return;
    else
    {
        int mid=(start+end)/2;
        merge_sort(arr,start,mid,n);
        merge_sort(arr,mid+1,end,n);
        merge_arrays(arr,start,mid,end);
    }
}
void insertion_sort(int arr[],int n)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}
int main()
{

    clock_t start_time,end_time;
    int n=200000000;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    arr[i]=rand();
    //system("clear");
    start_time=clock();
    merge_sort(arr,0,n-1,n);
    //selection_sort(arr,n);
    //bubble_sort(arr,n);
    //insertion_sort(arr,n);
    end_time=clock();
    double total_time=(double)(end_time-start_time)/CLOCKS_PER_SEC;
    // for(int i=0;i<n;i++)
    // cout<<arr[i]<<" ";
    cout<<"Total Time : "<<total_time<<endl;
}