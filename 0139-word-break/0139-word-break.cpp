class Solution {
    
    unordered_map<int, bool> dp;
    
    bool check(string &s, int idx, unordered_set<string> &st)
    {
        int n = s.length();
        if(idx == n)
            return true;
        if(dp.find(idx) != dp.end())
            return dp[idx];
        string curr = "";
        for(int i = idx; i < n; i++) {
            curr.push_back(s[i]);
            if(st.find(curr) != st.end() && check(s, i + 1, st)) {
                return dp[idx] = true;
            }
        }
        return dp[idx] = false;
    }
    
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> st;
        for(int i = 0; i < wordDict.size(); i++) st.insert(wordDict[i]);
        return check(s, 0, st);
    }
};