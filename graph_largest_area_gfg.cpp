//question link : https://practice.geeksforgeeks.org/problems/length-of-largest-region-of-1s-1587115620/1/?category[]=Graph&category[]=Graph&problemStatus=unsolved&difficulty[]=-1&difficulty[]=0&difficulty[]=1&page=1&query=category[]GraphproblemStatusunsolveddifficulty[]-1difficulty[]0difficulty[]1page1category[]Graph#

/*
sample input :
1
5 10
0 0 1 0 0 0 1 1 0 0
0 0 0 0 1 0 1 0 0 0
1 1 0 1 0 0 1 0 0 0
1 0 1 0 0 0 0 1 0 0
1 1 0 0 0 0 0 0 0 1

sample output : 8
*/
#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

class Solution
{
    public:
    //Function to find unit area of the largest region of 1s.
    int area(vector<vector<int> > grid,int  **visited,int i,int j,int n,int m)
    {
        if(i>=n || j>=m ||i<0 || j<0 || grid[i][j]==0 || visited[i][j]==1)
        return 0;
       visited[i][j]=1;
       int up=area(grid,visited,i-1,j,n,m);
       int down=area(grid,visited,i+1,j,n,m);
       int left=area(grid,visited,i,j-1,n,m);
       int right=area(grid,visited,i,j+1,n,m);
       int ldu=area(grid,visited,i-1,j-1,n,m);
       int rdu=area(grid,visited,i-1,j+1,n,m);
       int ldd=area(grid,visited,i+1,j-1,n,m);
       int rdd=area(grid,visited,i+1,j+1,n,m);
       return 1+up+down+left+right+ldu+rdu+ldd+rdd;
    }
    int findMaxArea(vector<vector<int> >& grid)
    {
        int **visited;
        visited=new int*[grid.size()];
        for(int i=0;i<grid.size();i++)
        {
            visited[i]=new int[grid[i].size()];
            for(int j=0;j<grid[i].size();j++)
            {
                visited[i][j]=0;
            }
        }
        int maxim=-1;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(visited[i][j]==0 && grid[i][j]==1)
                {
                    int temp_maxim=area(grid,visited,i,j,grid.size(),grid[i].size());
                    if(temp_maxim>maxim)
                    maxim=temp_maxim;
                }
            }
        }
        return maxim;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int> >grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.findMaxArea(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends