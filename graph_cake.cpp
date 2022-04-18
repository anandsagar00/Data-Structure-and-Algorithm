//find the largest piece of cake in a given cake
//almost same logic as explained in pep coding count island video

//link : https://www.youtube.com/watch?v=ErPZFxugYkI&list=PL-Jc9J83PIiHfqDcLZMcO9SsUDY4S3a-v&index=7
#include<iostream>
using namespace std;

int travel_all_four_sides(int **arr,int n,int i,int j,int **visited)
{
    //this function travels all four sides from a given vertex
    //i.e.
    //East , west north south

    //first we will check if we are inside the cake and there is a cake piece 
    //if not we will return
    if(i<0 || j<0 ||i>=n||j>=n || arr[i][j]==0 || visited[i][j]==1)
    return 0;

    //first of all we will mark visited at i,j = 1
    visited[i][j]=1;
    //now we will visit all four sides of a given piece
    int count=0;
    //north
    int north=travel_all_four_sides(arr,n,i-1,j,visited);
    //south
    int south=travel_all_four_sides(arr,n,i+1,j,visited);
    //east
    int east=travel_all_four_sides(arr,n,i,j+1,visited);
    //west
    int west=travel_all_four_sides(arr,n,i,j-1,visited);
    count=north+south+east+west;
    return count+1;
}
int largest_piece_of_cake(int **arr,int n)
{
    int **visited=new int*[n];
    for(int i=0;i<n;i++)
    {
        visited[i]=new int[n];
        for(int j=0;j<n;j++)
        visited[i][j]=0;
    }
    int max_cake_piece=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(arr[i][j]==1 && visited[i][j]==0)
            {
                //we will call travel function only when there exits a cake piece and which has not been visited
                int temp_max_cake_piece=travel_all_four_sides(arr,n,i,j,visited);
                if(temp_max_cake_piece > max_cake_piece)
                max_cake_piece=temp_max_cake_piece;
            }
        }
    }
    return max_cake_piece;
}
int main()
{
    int n;
    cout<<"Enter number of rows in the cake : ";
    cin>>n;
    int **arr;
    arr=new int*[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        cout<<"\nEnter cake pieces in row "<<i+1<<" : ";
        for(int j=0;j<n;j++)
        {
            int x;
            cin>>x;
            arr[i][j]=x;
        }
    }
    cout<<"\n\nYour cake is : \n";
    for(int i=0;i<n;i++)
    {
        cout<<"\n";
        for(int j=0;j<n;j++)
        {
            cout<<arr[i][j]<<" ";
        }
    }
    int max_cake_piece=largest_piece_of_cake(arr,n);
    cout<<"\n\nLargest piece of cake is : "<<max_cake_piece;
}