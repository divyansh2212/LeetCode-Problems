class Solution {
    
    int lcs(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp)
    {
        if(idx1 < 0 || idx2 < 0)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(s[idx1] == t[idx2])
            return dp[idx1][idx2] = 1 + lcs(idx1 - 1, idx2 - 1, s, t, dp);
        else
        {
            int way1 = lcs(idx1 - 1, idx2, s, t, dp);
            int way2 = lcs(idx1, idx2 - 1, s, t, dp);
            return dp[idx1][idx2] = max(way1, way2);
        }
    }
    
public:
    int longestCommonSubsequence(string s, string t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return lcs(n - 1, m - 1, s, t, dp);
    }
};