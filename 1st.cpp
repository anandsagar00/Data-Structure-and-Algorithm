// In this code I have tried to do basic array operation 
// Traverse − print all the array elements one by one.
// Insertion − Adds an element at the given index.

#include<bits/stdc++.h>
using namespace std;
typedef struct my_array
{
    int capacity;//max no. of elements held by aaray
    int length;//current count of elements in array
    int *arr; // array in heap
}my_array;

void display(my_array array)//function to display all relevant info related to array
{
    for(int i=0;i<array.length;i++)
    cout<<array.arr[i]<<" ";
    cout<<"\n";
    cout<<"Capacity : "<<array.capacity<<" Current length : "<<array.length<<endl;
}

my_array insert_at_index(my_array array,int index,int number) //to return the new structure after updating
{
    if(index<array.length)
    {
        for(int i=array.length;i>index;i--)
        array.arr[i]=array.arr[i-1];
        array.arr[index]=number;
        array.length++;
    }
    else
    {
        array.arr[index]=number;
        array.length++;
    }
    return array;
}

int main()
{
    my_array array;
    cout<<"Enter the total capacity of array :\n"<<endl;
    cin>>array.capacity;
    array.arr=new int[array.capacity];
    cout<<"Enter number of elements you want to input as of now :\n";
    cin>>array.length;

    if(array.length<=array.capacity)
    {
        for(int i=0;i<array.length;i++)
        {
            cout<<"Enter element at index "<<i<<" : ";
            cin>>array.arr[i];
            cout<<endl;
        }
    }
    else
    cout<<"You can't enter elements more than the size of array."<<endl;

    while(1)
    {
        int index,number;
        cout<<"Enter the index at which you want to insert the number (or negative index to exit) :\n";
        cin>>index;
        if(index<0)
        {
            cout<<"------------------------BYE-------BYE------------------------------\n";
            break;
        }
        cout<<"Enter the number to insert :\n";
        cin>>number;
        if(index <= array.length && array.length<array.capacity)
        {
            array=insert_at_index(array,index,number);
            display(array);
        }
        else
        {
            if(index>array.length)
            cout<<"This is an invalid Index.Please try again with a valid index.\n";
            else if(array.length==array.capacity)
            {
                cout<<"Array is already filled full of its capacity.\n\t\t\t\t\t\t\t\t\t\t\t\t\tBye";
                break;
            }
        }
    }

}