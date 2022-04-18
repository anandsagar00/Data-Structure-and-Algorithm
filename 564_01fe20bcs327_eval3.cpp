#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;

void merge_arays(int arr[],int start,int end,int mid,long int &swaps_merge)
{
    int size=(end-start)+1;
    int *arr1=new int[size];
    int k=0;
    int i=start;
    int j=mid+1;
    //first we will copy all the elements in chronological order till where possible
    while(i<=mid && j<=end)
    {
        if(arr[i]<arr[j])
        arr1[k++]=arr[i++];
        else
        arr1[k++]=arr[j++];
        swaps_merge++;
    }
    //copy down the remaining elements
    while(i<=mid)
    arr1[k++]=arr[i++];
    while(j<=end)
    arr1[k++]=arr[j++];
    //copy back all elements from new array to old array
    for(int l=0;l<size;l++)
    arr[start++]=arr1[l];
}
void merge_sort(int arr[],int start,int end,long int &swaps)
{
    if(start>=end)
    return;
    else
    {
        int mid=(start+end)/2;
        merge_sort(arr,start,mid,swaps);
        merge_sort(arr,mid+1,end,swaps);
        merge_arays(arr,start,end,mid,swaps);
    }
}

void bubble_sort(int arr[],int n,long int &swaps)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                swaps++;
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void insertion_sort(int arr[],int n,long int &swaps)
{
    for(int i=1;i<n;i++)
    {
        int j=i-1;
        int temp=arr[i];
        while(j>0 && arr[j]>temp)
        {
            swaps++;
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
}

void selection_sort(int arr[],int n,long int &swaps)
{
    for(int i=0;i<n-1;i++)
    {
        int select=i+1;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[select])
            {
                select=j;
            }
        }
        swaps++;
        int temp=arr[select];
        arr[select]=arr[i];
        arr[i]=temp;
    }
}

int main()
{
    srand(time(NULL));
    int n=abs(rand());
    n=n%1000000;
    int *arr=new int[n];
    for(int i=0;i<n;i++)
    arr[i]=rand();
    long int swaps=0;

    clock_t start_time,end_time;

    start_time=clock();
    bubble_sort(arr,n,swaps);
    end_time=clock();
    double t=double(end_time-start_time)/CLOCKS_PER_SEC;
    cout<<"Total Swaps bubble sort : "<<swaps<<endl;
    cout<<"Total time bubble sort : "<<t<<endl;
    cout<<endl;

    for(int i=0;i<n;i++)
    arr[i]=rand();
    swaps=0;
    start_time=clock();
    insertion_sort(arr,n,swaps);
    end_time=clock();
    t=double(end_time-start_time)/CLOCKS_PER_SEC;
    cout<<"Total Swaps insertion sort : "<<swaps<<endl;
    cout<<"Total time insertion sort : "<<t<<endl;
    cout<<endl;

    for(int i=0;i<n;i++)
    arr[i]=rand();
    swaps=0;
    start_time=clock();
    selection_sort(arr,n,swaps);
    end_time=clock();
    t=double(end_time-start_time)/CLOCKS_PER_SEC;
    cout<<"Total Swaps selection sort : "<<swaps<<endl;
    cout<<"Total time selection sort : "<<t<<endl;
    cout<<endl;

    for(int i=0;i<n;i++)
    arr[i]=rand();
    swaps=0;
    start_time=clock();
    merge_sort(arr,0,n-1,swaps);
    end_time=clock();
    t=double(end_time-start_time)/CLOCKS_PER_SEC;
    cout<<"Total Swaps Merge sort : "<<0<<endl;
    cout<<"Total time Merge sort : "<<t<<endl;
    cout<<endl;

    cout<<"INPUT SIZE : "<<n<<endl;

}