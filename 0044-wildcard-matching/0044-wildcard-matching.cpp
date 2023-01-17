class Solution {
    
    bool check(int idx1, int idx2, string &s, string &p, vector<vector<int>> &dp)
    {
        int n = s.length(), m = p.length();
        if(idx1 == n && idx2 == m)
            return true;
        if(idx2 == m)
            return false;
        
        if(idx1 == n)
        {
            int i = idx2;
            while(i < m)
            {
                if(p[i] != '*')
                    return dp[idx1][idx2] = false;
                i++;
            }
            return dp[idx1][idx2] = true;
        }
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(p[idx2] == '?')
            return dp[idx1][idx2] = check(idx1 + 1, idx2 + 1, s, p, dp);
            
        
        if(p[idx2] == '*')
        {
            bool way1 = check(idx1 + 1, idx2 + 1, s, p, dp);
            bool way2 = check(idx1 + 1, idx2, s, p, dp);
            bool way3 = check(idx1, idx2 + 1, s, p, dp);
            
            return dp[idx1][idx2] = (way1 | way2 | way3);
        }
        
        else if(s[idx1] != p[idx2])
            return dp[idx1][idx2] = false;   
        else
            return dp[idx1][idx2] = check(idx1 + 1, idx2 + 1, s, p, dp);
    }
    
public:
    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));
        return check(0, 0, s, p, dp);
    }
};