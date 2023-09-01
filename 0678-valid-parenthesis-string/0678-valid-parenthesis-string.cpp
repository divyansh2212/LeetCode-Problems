class Solution {
    
    map<pair<int, int>, bool> dp;
    
    bool solve(int idx, string &s, int open)
    {
        int n = s.length();
        if(idx == n)
            return (open == 0);
        
        if(dp.find({idx, open}) != dp.end())
            return dp[{idx, open}];
        
        if(s[idx] == '(') {
            return dp[{idx, open}] = solve(idx + 1, s, open + 1);
        }
        else if(s[idx] == ')') {
            if(open == 0) return dp[{idx, open}] = false;
            return dp[{idx, open}] = solve(idx + 1, s, open - 1);
        }
        else {
            bool flag = solve(idx + 1, s, open);
            if(open) {
                flag |= solve(idx + 1, s, open - 1);
            }
            flag |= solve(idx + 1, s, open + 1);
            
            return dp[{idx, open}] = flag;
        }
    }
    
public:
    bool checkValidString(string s) {
        int n = s.length();
        int open = 0;
        
        return solve(0, s, open);
    }
};