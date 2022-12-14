class Solution {
    int solve(int idx, vector<int> &nums, int last, vector<vector<int>> &dp)
    {
        if(idx == nums.size())
            return 0;
        if(dp[idx][last + 1] != -1)
            return dp[idx][last + 1];
        
        int pick = 0, notPick = 0;
        if(last == -1 || idx - last > 1)
            pick = nums[idx] + solve(idx + 1, nums, idx, dp);
            notPick = solve(idx + 1, nums, last, dp);
        
        return dp[idx][last + 1] = max(pick, notPick);
    }
    
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 2, 0));
        
        // return solve(0, nums, -1, dp);
        
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int last = idx - 1; last >= -1; last--)
            {
                // if(last >= idx)
                //     continue;
                int pick = 0, notPick = 0;
                if(last == -1 || idx - last > 1)
                    pick = nums[idx] + dp[idx + 1][idx + 1];

                    notPick = dp[idx + 1][last + 1];
        
                dp[idx][last + 1] = max(pick, notPick);
            }
        }
        
        return dp[0][0];
    }
};