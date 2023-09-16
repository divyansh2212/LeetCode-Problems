//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    const int mod = 1000000007;
    
    long long solve(int target, vector<long long> &dp)
    {
        if(target < 0)
            return 0;
        if(target == 0)
            return 1;
        
        if(dp[target] != -1)
            return dp[target];
            
        long long way1 = solve(target - 1, dp);
        long long way2 = solve(target - 2, dp);
        long long way3 = solve(target - 3, dp);
        
        return dp[target]=(way1 + way2  + way3) % mod;
    }
    
    public:
    //Function to count the number of ways in which frog can reach the top.
    long long countWays(int n)
    {
        vector<long long> dp(n+1, -1);
        return solve(n, dp);
        
    }
};


//{ Driver Code Starts.
int main()
{
    //taking testcases
	int t;
	cin >> t;
	
	while(t--)
	{
	    //taking number of steps in stair
		int n;
		cin>>n;
		Solution ob;
		//calling function countWays()
		cout << ob.countWays(n) << endl;
	}
    
    return 0;
    
}

// } Driver Code Ends