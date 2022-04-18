//In this code I have tried to implement heap data structure 
//I have tried to make a min heap i.e minimum element at the top and performed all operations such as insert,delete and get min etc.
//Later I have tried to make a max heap i.e maximum element at the top and performed all operations such as insert,delete and get min etc.

//properties of a heap is that it must be a complete binary tree i.e. all levels must be filled completely and the last
//level must be filled from left to right

//If an element is kept at i index then it's children are kept at 2i+1 and 2i+2
//conversly if an element is kept at i th index then its parent is at (i-1)/2

//Detailed explanation in Coding Ninjas course Priority Queue Folder
#include<iostream>
#include<limits.h>
using namespace std;
struct heap
{
    int *arr;
    int last_index;
};
int main()
{
    int n;
    cout<<"Enter number of elements in the heap : ";
    cin>>n;
    heap min_heap;
    min_heap.arr=new int[n];
    min_heap.last_index=-1;
    for(int i=0;i<n;i++)
    {
        min_heap.last_index=i;
        cin>>min_heap.arr[min_heap.last_index];
        int curr_index=i;
        int parent_index=(curr_index-1)/2;
        while(parent_index>=0 && min_heap.arr[parent_index]>min_heap.arr[curr_index])
        {
            int temp=min_heap.arr[curr_index];
            min_heap.arr[curr_index]=min_heap.arr[parent_index];
            min_heap.arr[parent_index]=temp;
            curr_index=parent_index;
            parent_index=(curr_index-1)/2;
        }
    }
    cout<<"\nElements of min heap are : ";
    for(int i=0;i<=min_heap.last_index;i++)
    cout<<min_heap.arr[i]<<" ";
    cout<<endl;
    while(1)
    {
        cout<<"Press 1 to delete element from min heap.";
        cout<<"\nPress 2 to exit.\n";
        int choice;
        cin>>choice;
        if(choice==1)
        {
            int temp=min_heap.arr[min_heap.last_index];
            min_heap.arr[0]=temp;
            min_heap.last_index=min_heap.last_index-1;
            int curr_index=0;
            int first_child_inedex=curr_index*2+1;
            int second_child_index=curr_index*2+2;
            
        }
        else
        {
            cout<<"____________________________________________-EXIT-________________________________________________________"<<endl;
            break;
        }
        cout<<endl;
        for(int i=0;i<=min_heap.last_index;i++)
        cout<<min_heap.arr[i]<<" ";
        cout<<endl;
    }
}