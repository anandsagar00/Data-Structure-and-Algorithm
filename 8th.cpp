//left rotate an array bu 1
// I/P : 1 2 3 4 , rotate by 1 
//O/P : 2 3 4 1
// I/P : 1 2 3 4 , rotate by 3
//O/P : 4 1 2 3
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter numeber of elements in an array :\n";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in the array :"<<endl;
    for(int i=0;i<n;i++)
    {
        cout<<": ";
        cin>>arr[i];
    }
    cout<<"\nEnter the number by how much you want to rotate the array\n";
    int d;
    cin>>d;
    cout<<"New rotated array is :\n";
    if(n==1)
    {
        cout<<arr[0];
    }
    else
    {
        int i=1;
        while(d>0)//each time rotates the array by 1 in left
        {
            int temp=arr[0];
            for(int i=0;i<n-1;i++)//in this loop we rotate the array in left by on1
            {
                arr[i]=arr[i+1];
            }
            arr[n-1]=temp;
            cout<<"\nIn rotation "<<i<<" : \n"<<endl;
            for(int i=0;i<n;i++)
            {
                cout<<arr[i]<<" ";
            }
            d--;
            i++;
        }
    }
}