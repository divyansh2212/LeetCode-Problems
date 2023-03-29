class Solution {
    
    int solve(int idx, int time, vector<int>& satisfaction, vector<vector<int>> &dp)
    {
        int n = satisfaction.size();
        if(idx == n) return 0;
        
        if(dp[idx][time] != -1)
            return dp[idx][time];
        
        int way1 = (satisfaction[idx] * time) + solve(idx + 1, time + 1, satisfaction, dp);
        int way2 = solve(idx + 1, time, satisfaction, dp);
        
        return dp[idx][time] = max(way1, way2);
    }
    
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end());
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        
        
        return solve(0, 1, satisfaction, dp);
        
    }
};