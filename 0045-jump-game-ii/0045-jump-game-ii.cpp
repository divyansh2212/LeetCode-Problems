class Solution {
    
    int solve(int idx, vector<int>& nums, vector<int> &dp)
    {
        int n = nums.size();
        if(idx >= n)
            return 1e9;
        if(idx == n - 1)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        
        int jumps = 1e9;
        for(int i = 1; i <= nums[idx]; i++)
            jumps = min(jumps, 1 + solve(idx + i, nums, dp));
        
        return dp[idx] = jumps;
    }
    
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, dp);
    }
};