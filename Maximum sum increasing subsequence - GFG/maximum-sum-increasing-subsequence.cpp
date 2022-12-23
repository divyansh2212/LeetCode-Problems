//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		
	int solve(int idx, int last, int arr[], int &n, vector<vector<int>> &dp)
	{
	    if(idx == n)
	        return 0;
	       
	    if(dp[idx][last + 1] != -1)
	        return dp[idx][last + 1];
	    
	    int way1 = 0, way2 = 0;
	    way1 = solve(idx + 1, last, arr, n, dp);
	    if(last == -1 || arr[last] < arr[idx])
	        way2 = arr[idx] + solve(idx + 1, idx, arr, n, dp);
	    
	    return dp[idx][last + 1] = max(way1, way2);
	}

	public:
	int maxSumIS(int arr[], int n)  
	{  
	    // Your code goes here
	    vector<vector<int>> dp(n, vector<int> (n + 1, -1));
	    return solve(0, -1, arr, n, dp);
	}  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

      

	    Solution ob;
	    cout << ob.maxSumIS(a, n) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends