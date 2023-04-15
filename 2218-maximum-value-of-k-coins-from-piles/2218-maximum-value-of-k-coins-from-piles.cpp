class Solution {
    
    int solve(vector<vector<int>>& piles, int k, int idx, vector<vector<int>> &dp)
    {
        int n = piles.size();
        if(idx == n || k == 0)
            return 0;
        if(dp[idx][k] != -1)
            return dp[idx][k];
        int m = piles[idx].size();
        
        int maxi = solve(piles, k, idx + 1, dp);
        
        for(int i = 1; i <= min(m, k); i++)
        {
            maxi = max(maxi, piles[idx][i - 1] + solve(piles, k - i, idx + 1, dp));
        }
        
        return dp[idx][k] = maxi;
    }
    
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        
        int n = piles.size();
        
        for(int i = 0; i < n; i++)
        {
            int m = piles[i].size();
            for(int j = 1; j < m; j++)
                piles[i][j] += piles[i][j - 1];
        }
        
        vector<vector<int>> dp(n, vector<int> (k + 1, -1));
        
        return solve(piles, k, 0, dp);
    }
};