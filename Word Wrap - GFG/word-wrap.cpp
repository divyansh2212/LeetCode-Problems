//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    int solve(int idx, vector<int> &nums, int &k, vector<int> &dp)
    {
        int n = nums.size();
        if(idx >= n- 1)
            return 0;
        
        if(dp[idx] != -1)    
            return dp[idx];
        int ans = 1e9;
        
        int curr = 0;
        for(int i = idx; i < n; i++) {
            if(i == idx) {
                curr += nums[i];
            }
            else {
                curr += nums[i] + 1;
            }
            if(curr > k)
                break;
            if(i != n - 1)
                ans = min(ans, (k - curr) * (k - curr) + solve(i + 1, nums, k, dp));
            else
                ans = min(ans, solve(i + 1, nums, k, dp));
        }
        return dp[idx]=ans;
    }
    
public:
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        int n = nums.size();
        
        vector<int> dp(n, -1);
        
        return solve(0, nums, k, dp);
    } 
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, k;
        cin >> n;
        vector<int>nums(n);
        for (int i = 0; i < n; i++)cin >> nums[i];
        cin >> k;
        Solution obj;
        cout << obj.solveWordWrap(nums, k) << endl;
	}
	return 0;
}
// } Driver Code Ends