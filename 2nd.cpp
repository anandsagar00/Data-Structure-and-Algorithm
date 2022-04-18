//normal array operation like delete search,update 

#include<bits/stdc++.h>
using namespace std;

typedef struct my_array
{
    int *arr;//array in heap
    int cap;//total capacity of array
    int len;//current length of array
}my_array;

void bubble_sort(int arr[],int len)//sort array using bubble sort algorithm
{
    for(int i=0;i<len-1;i++)
    {
        for(int j=0;j<len-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

void display(my_array array)//displays the given array
{
    for(int i=0;i<array.len;i++)
    cout<<array.arr[i]<<" ";
    cout<<"Capacity : "<<array.cap<<" Length : "<<array.len<<endl;
}

my_array del_array(my_array array,int ind)//deletes an element at a given index
{
    if(ind==array.len-1)
    {
        array.len-=1;
    }
    else
    {
        for(int i=ind;i<array.len-1;i++)
        array.arr[i]=array.arr[i+1];
        array.len-=1;
    }
    return array;
}
my_array update(my_array array,int ind,int number)//updates the value at a given index
{
    if(ind<0 || ind > array.len)
    {
        cout<<"Invalid Index"<<endl;
    }
    else
    {
        array.arr[ind]=number;
    }
    return array;
}
int search(int arr[],int n,int key)//returns 0 or 1 depending on key is present in array or not
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==key)
        return 1;
    }
    return 0;
}

int main()
{
    my_array array;
    cout<<"Enter the capacity of array :\n";
    cin>>array.cap;
    array.arr=new int[array.cap];
    user_input://goto label
                cout<<"Enter the number of elements you want to enter :\n";
                cin>>array.len;
    if(array.len<=array.cap)
    {
    for(int i=0;i<array.len;i++)
    {
        cout<<"Enter the elements at index "<<i<<endl;
        cin>>*(array.arr+i);//using dereferencing pointer technique to input in array
    }
    }
    else
    {
        cout<<"The number of elements in an array can't exceed its capacity.\n";
        cout<<"Please enter again!!\n";
        goto user_input;

    }

    while(true)
    {
        cout<<"Press 1 to delete an element at a given index\n";
        cout<<"Press 2 to sort the array\n";
        cout<<"press 3 to search if a key is present in array or not\n";
        cout<<"Press 4 or any other key to exit\n";
        cout<<"Enter choice : ";
        
        int choice;
        cin>>choice;
        system("clear");
        if(choice==1)
        {
            int ind;
            cout<<"Enter index which you want to delete :\n";
            cin>>ind;
            if(ind<0)
            {
                cout<<"Invalid Index.\n";
            }
            else if(array.len==0)
            {
                cout<<"Array is already empty.\n";
            }
            else if(ind>array.len)
            {
                cout<<"Invalid Index.\n";
            }
            else
            {
                array=del_array(array,ind);
                cout<<"Update array is : \n";
                display(array);
            }
        }
        else if(choice==2)
        {
            bubble_sort(array.arr,array.len);
            cout<<"Update array is : \n";
            display(array);
        }
        else if(choice == 3)
        {
            int key;
            cout<<"Enter the key :\n";
            cin>>key;
            if(search(array.arr,array.len,key))
            cout<<"The given key : "<<key<<" is present in array.\n";
            else
            cout<<"The given key : "<<key<<" is not present in array.\n";
        }
        else
        {
            cout<<"____________________________________BYE--------BYE_____________________________________"<<endl;
            break;
        }
        
    }
}