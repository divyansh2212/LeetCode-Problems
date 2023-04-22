class Solution {

    int solve(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp)
    {
        int n = s.length();
        if(idx1 == n || idx2 == n)
            return 0;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(s[idx1] == t[idx2])
            return dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2 + 1, s, t, dp);
        else
        {
            int way1 = solve(idx1 + 1, idx2, s, t, dp);
            int way2 = solve(idx1, idx2 + 1, s, t, dp);
            
            return dp[idx1][idx2] = max(way1, way2);
        }
    }
    
    public:
    int minInsertions(string s) {
        int n = s.length();
        string t = s;
        reverse(t.begin(), t.end());
        
        vector<vector<int>> dp(n, vector<int>(n, -1));
        
        return n - solve(0, 0, s, t, dp);
    }
};