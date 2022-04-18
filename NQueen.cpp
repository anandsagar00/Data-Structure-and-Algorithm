//In this code I will be trying to solve a very famous problem known as N-Queen problem
/*
Place N queens on a NxN chess board such that no queens cancel each other

This N-Queen problem doesn't give a solution for 3 queens on a 3x3 board
*/

#include<iostream>
using namespace std;
int board[8][8]={{0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},
                 {0,0,0,0,0,0,0,0},};
bool isSafeToPlace(int row,int col,int n)
{
    //in this function we will check if it is possible to place a queen on the board at [row,col]
    //if it will not be possible then we will retun false

    //we will check if any queen is already placed vertically up
    int r=row-1;
    int c=col;
    while(r>=0)
    {
        if(board[r][c]==1)
        return false;
        r=r-1;
    }
    // check for if the any queen is already in left direction

    r=row;
    c=col-1;
    while(c>=0)
    {
        if(board[r][c]==1)
        return false;
        c=c-1;
    }
    r=row-1;
    c=col-1;
    // we will check if any queen is placed in diagonally left direction or not
    while(r>=0 && c>=0)
    {
        if(board[r][c]==1)
        return false;
        r=r-1;
        c=c-1;
    }

    //we will check if any queen is there or not in the right diagonal

    r=row-1;
    c=col+1;
    while(r>=0 && c<n)
    {
        if(board[r][c]==1)
        return false;
        r=r-1;
        c=c+1;
    }
    //if all the above loops/condition states that it is safe then we will return true
    return true;
}

void placeQueens(int row,int n,int tq,string s)
{
    if(tq==n)
    {
        cout<<s<<endl;
        return;
    }
    for(int col=0;col<n;col++)
    {
        if(isSafeToPlace(row,col,n))
        {
            board[row][col]=1;
            placeQueens(row+1,n,tq+1,s+"("+to_string(row)+","+to_string(col)+")-");
            board[row][col]=0;
        }
    }
}
int main()
{
        int n=8;
        string s="";
        placeQueens(0,n,0,s);
}