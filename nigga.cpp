#include<iostream>
using namespace std;

int check_special(int n)
{
    int prev_dig=-1;
    while(n>0)
    {
        if(n%10<prev_dig)
            return 0;
        n/=10;
    }
    return 1;
}

int find_answer(int arr[],int n)
{
    int count = 0;
    for(int i=0;i<n;i++)
    {
        int temp=check_special(arr[i]);
        count+=temp;
    }
    return count;
}

int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    int answer = find_answer(arr,n);
    cout<<answer<<endl;
}