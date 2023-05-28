class Solution {
    
    unordered_map<int, unordered_map<int, int>> dp;
    
    int solve(int start, int end, vector<int>& cuts)
    {
        if(start >= end)
            return 0;
        
        if(dp.find(start) != dp.end() && dp[start].find(end) != dp[start].end())
            return dp[start][end];
        
        int cost = INT_MAX;
        
        for(int i = 0; i < cuts.size(); i++)
        {
            if(cuts[i] > start && cuts[i] < end)
            {
                cost = min(cost, end - start + solve(start, cuts[i], cuts) + solve(cuts[i], end, cuts));
            }
        }
        
        if(cost==INT_MAX) cost = 0;
        return dp[start][end] = cost;
    }
    
public:
    int minCost(int n, vector<int>& cuts) {
        dp.clear();
        // vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return solve(0, n, cuts);
    }
};