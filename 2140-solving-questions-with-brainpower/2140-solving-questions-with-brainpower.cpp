class Solution {
    
    long long solve(vector<vector<int>>& questions, int idx, vector<long long> &dp)
    {
        int n = questions.size();
        if(idx >= n)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        long long way1 = questions[idx][0] + solve(questions, idx + questions[idx][1] + 1, dp);
        long long way2 = solve(questions, idx + 1, dp);
        
        return dp[idx] = max(way1, way2);
    }
    
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        return solve(questions, 0, dp);
    }
};