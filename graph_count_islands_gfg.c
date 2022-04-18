/*
Given a grid consisting of '0's(Water) and '1's(Land). Find the number of islands.
Note: An island is surrounded by water and is formed by connecting adjacent lands
horizontally or vertically or diagonally i.e., in all 8 directions.
*/
//lesson learnt : read the question completely don't be in a hurry

// Program to count islands in boolean 2D matrix
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define COL 501


 // } Driver Code Ends
// User function Template for C
#include<stdlib.h>
void dfs_on_islands(int grid[][COL],int i,int j,int n,int m,int **visited)
    {
         if(i<0 || j<0 || i>=n || j>=m||grid[i][j] == 0 )
        return;
        visited[i][j]=1;
        //up
        dfs_on_islands(grid,i-1,j,n,m,visited);
        //down
        dfs_on_islands(grid,i+1,j,n,m,visited);
        //left
        dfs_on_islands(grid,i,j-1,n,m,visited);
        //right
        dfs_on_islands(grid,i,j+1,n,m,visited);
        //top left diagonal
        dfs_on_islands(grid,i-1,j-1,n,m,visited);
        //top right diagonal
        dfs_on_islands(grid,i-1,j+1,n,m,visited);
        //bottom left diagonal
        dfs_on_islands(grid,i+1,j-1,n,m,visited);
        //top right diagonal
        dfs_on_islands(grid,i+1,j+1,n,m,visited);
    }

int countIslands(int arr[][COL], int n, int m) {
    int **visited=(int **)malloc(n*sizeof(int *));
    for(int i=0;i<n;i++)
    {
        visited[i]=(int *)malloc(m*sizeof(int));
        for(int j=0;j<m;j++)
        visited[i][j]=0;
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(visited[i][j]==0)
            {
                dfs_on_islands(arr,i,j,n,m,visited);
                count++;
            }
        }
    }
    return count;
}


// { Driver Code Starts.

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {

        int n, m;
        scanf("%d %d", &n, &m);

        int M[n][COL];

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &M[i][j]);
            }
        }

        int ans = countIslands(M, n, m);
        printf("%d\n", ans);
    }

    return 0;
}
  // } Driver Code Ends