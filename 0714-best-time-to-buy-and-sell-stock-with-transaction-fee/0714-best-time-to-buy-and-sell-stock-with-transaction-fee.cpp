class Solution {
    
    int solve(int idx, vector<int>& prices, int &fee, bool canBuy, vector<vector<int>> &dp)
    {
        int n = prices.size();
        
        if(idx == n)
            return 0;
        
        if(dp[idx][canBuy] != INT_MAX)
            return dp[idx][canBuy];
        
        if(canBuy)
        {
            int way1 = solve(idx + 1, prices, fee, canBuy, dp);
            int way2 = solve(idx + 1, prices, fee, 0, dp) - prices[idx];
            
            return dp[idx][canBuy] = max(way1, way2);
        }
        else
        {
            int way1 = solve(idx + 1, prices, fee, canBuy, dp);
            int way2 = solve(idx + 1, prices, fee, 1, dp) + prices[idx] - fee;
            
            return dp[idx][canBuy] = max(way1, way2);
        }
    }
    
public:
    int maxProfit(vector<int>& prices, int fee) {
        
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (2, INT_MAX));
        return solve(0, prices, fee, 1, dp);
        
    }
};