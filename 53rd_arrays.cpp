//create an array where each row had different coloums/where coloumns are taken as user input
#include<iostream>>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of rows : ";
    cin>>n;
    int *arr[n];  //creating an array of pointers since this is an array it will be created in stack

    for(int i=0;i<n;i++)
    {
        int n1;
        cout<<"Enter number of coloums for row "<<i+1<<" : ";
        cin>>n1;
        arr[i]=new int[n1];
        cout<<"Enter elements : \n";
        for(int j=0;j<n1;j++)
        {
            cout<<": ";
            cin>>arr[i][j];
        }
    }

}