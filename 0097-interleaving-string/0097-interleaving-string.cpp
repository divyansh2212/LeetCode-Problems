class Solution {
    
    map<vector<int>, bool> dp;
    bool check(int idx1, int idx2, int idx3, string &s1, string &s2, string &s3)
    {
        int n = s1.length(), m = s2.length();
        if(idx3 == s3.length()) return true;
        
        if(dp.find({idx1, idx3}) != dp.end())
            return dp[{idx1, idx3}];
        
        if(idx2 == m) {
            while(idx1 < n) {
                if(s1[idx1] != s3[idx3])
                    return false;
                idx1++, idx3++;
            }
            return true;
        }
        if(idx1 == n) {
            while(idx2 < m) {
                if(s2[idx2] != s3[idx3])
                    return false;
                idx2++, idx3++;
            }
            return true;
        }
        
        bool flag1 = false, flag2 = false;
        if(s1[idx1] == s3[idx3]) {
            flag1 = check(idx1 + 1, idx2, idx3 + 1, s1, s2, s3);
        }
        if(s2[idx2] == s3[idx3]) {
            flag2 = check(idx1, idx2 + 1, idx3 + 1, s1, s2, s3);
        }
        
        return dp[{idx1, idx3}] = (flag1 | flag2);
    }
    
    public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();
        
        if(n + m != s3.length()) return false;
        
        return check(0, 0, 0, s1, s2, s3);
    }
};