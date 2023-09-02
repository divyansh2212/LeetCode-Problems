class Solution {
public:
    int solve(string& s, unordered_set<string> &st, vector<int>&dp, int index)
    {
        if (index >= s.size()) return 0;
        if (dp[index] != -1) 
            return dp[index];
        
        string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
        
            int curr = solve(s, st, dp, cutIdx + 1);
            if(st.find(currStr) == st.end())
                curr += currStr.length();
            
            minExtra = min(minExtra, curr);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dict) 
    {
        vector<int>dp(s.size(), -1);
        unordered_set<string> st(dict.begin(), dict.end());
        
        int ans = solve(s, st, dp, 0);
        return ans;
        
    }
};