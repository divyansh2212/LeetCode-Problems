class Solution {
    
    int solve(int idx, int last, vector<vector<int>>& pairs, vector<vector<int>> &dp)
    {
        int n = pairs.size();
        if(idx == n)
            return 0;
        if(dp[idx][last + 1] != -1)
            return dp[idx][last + 1];
        int way1 = solve(idx + 1, last, pairs, dp);
        int way2 = 0;
        if(last == -1 || pairs[idx][0] > pairs[last][1]) {
            way2 = 1 + solve(idx + 1, idx, pairs, dp);
        }
        return dp[idx][last + 1] = max(way1, way2);
    }
    
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        return solve(0, -1, pairs, dp);
    }
};