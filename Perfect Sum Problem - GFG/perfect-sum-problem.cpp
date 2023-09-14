//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    const int mod = 1e9 + 7;
    
    int solve(int idx, int target, int arr[], int n, vector<vector<int>> &dp)
    {
        if(idx == n || target < 0)
            return 0;
        if(dp[idx][target] != -1)
            return dp[idx][target];
            
        int way1 = solve(idx + 1, target, arr, n, dp);
        int way2 = 0;
        if(target > arr[idx])
            way2 = solve(idx + 1, target - arr[idx], arr, n, dp);
        else if(target == arr[idx])
            way2 = 1 + solve(idx + 1, 0, arr, n, dp);
        
        return dp[idx][target]=(way1 + 0LL + way2) % mod;
    }
    
	public:
	int perfectSum(int arr[], int n, int sum)
	{
        // Your code goes here
        vector<vector<int>> dp(n, vector<int> (sum + 1, -1));
        return solve(0, sum, arr, n, dp);
	}
	  
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, sum;

        cin >> n >> sum;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.perfectSum(a, n, sum) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends