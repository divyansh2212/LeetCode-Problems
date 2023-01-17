class Solution {
    
    int minmCost(int idx, int last, string &s, vector<vector<int>> &dp)
    {
        if(idx == s.length())
            return 0;
        
        if(dp[idx][last] != -1)
            return dp[idx][last];
        
        if(last == 0)
        {
            int way1 = 1e9, way2 = 1e9;
            if(s[idx] == '1')
            {
                // making it 0
                way1 = 1 + minmCost(idx + 1, 0, s, dp);
                
                // keeping it 1
                way2 = minmCost(idx + 1, 1, s, dp);
            }
            
            else
            {
                // keeping it 0
                way1 = minmCost(idx + 1, 0, s, dp);
                
                // making it 1
                way2 = 1 + minmCost(idx + 1, 1, s, dp);
            }
            
            return dp[idx][last] = min(way1, way2);
        }
        
        else
        {
            int way1;
            if(s[idx] == '1')
                way1 = minmCost(idx + 1, 1, s, dp);
            else
                way1 = 1 + minmCost(idx + 1, 1, s, dp);
            
            return dp[idx][last] = way1;
        }
        
    }
    
public:
    int minFlipsMonoIncr(string s) {
        vector<vector<int>> dp(s.length(), vector<int> (2, -1));
        return minmCost(0, 0, s, dp);
    }
};