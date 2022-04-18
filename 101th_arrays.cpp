// merge k sorted arrrays
//silly mistake was I was using size() function
#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


 // } Driver Code Ends
//User function Template for C++


class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int> > arr, int k)
    {
        if(k==1)
        return arr[0];
        vector <int> temp_final;
        vector <int> v1;
        v1=arr[0];
        vector<int> v2;
        for(int l=1;l<k;l++)
        {
            v2=arr[l];
            int i=0,j=0;
            while(i<l*k && j<k)
            {
                if(v1[i]<=v2[j])
                {
                    temp_final.push_back(v1[i]);
                    i++;
                }
                else
                {
                     temp_final.push_back(v2[j]);
                     j++;
                }
            }
            while(i<l*k)
            {
                int x=v1[i++];
                temp_final.push_back(x);
            }
             while(j<k)
             {
                 int x=v2[j++];
                 temp_final.push_back(x);
             }
            v1.clear();
            v2.clear();
            v1=temp_final;
            if(l<(k-1))
            temp_final.clear();
            
        }
        return temp_final;
        
    }
};

// { Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector< vector<int> > arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}





  // } Driver Code Ends