class Solution {
    
    int solve(string &word1, string &word2, int idx1, int idx2, vector<vector<int>> &dp)
    {
        int n = word1.length(), m = word2.length();
        if(idx1 == n && idx2 == m)
            return 0;
        if(idx1 == n)
            return m - idx2;
        if(idx2 == m)
            return n - idx1;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(word1[idx1] == word2[idx2])
            return dp[idx1][idx2] = solve(word1, word2, idx1 + 1, idx2 + 1, dp);
        else
        {
            int way1 = 1 + solve(word1, word2, idx1 + 1, idx2 + 1, dp);
            int way2 = 1 + solve(word1, word2, idx1 + 1, idx2, dp);
            int way3 = 1 + solve(word1, word2, idx1, idx2 + 1, dp);
            return dp[idx1][idx2] = min({way1, way2, way3});
        }
        
    }
    
public:
    int minDistance(string word1, string word2) {
        int n = word1.length(), m = word2.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return solve(word1, word2, 0, 0, dp);
    }
};