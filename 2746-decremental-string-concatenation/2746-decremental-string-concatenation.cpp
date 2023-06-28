class Solution {
    
    map<vector<int>, int> dp;
    
    int solve(vector<string>& words, int idx, char ch1, char ch2)
    {
        int n = words.size();
        if(idx >= n)
            return 0;
        if(dp.find({idx, ch1 - 'a', ch2 - 'a'}) != dp.end())
            return dp[{idx, ch1 - 'a', ch2 - 'a'}];
        int m = words[idx].length();
        
        
        int way1 = 0, way2 = 0;
        
        if(ch2 == words[idx][0]) {
            way1 = m - 1 + solve(words, idx + 1, ch1, words[idx][m - 1]);
        }
        else {
            way1 = m + solve(words, idx + 1, ch1, words[idx][m - 1]);
        }
        
        if(words[idx][m - 1] == ch1) {
            way2 = m - 1 + solve(words, idx + 1, words[idx][0], ch2);
        }
        else {
            way2 = m + solve(words, idx + 1, words[idx][0], ch2);
        }
        
        return dp[{idx, ch1 - 'a', ch2 - 'a'}] = min(way1, way2);
    }
    
public:
    int minimizeConcatenatedLength(vector<string>& words) {
        int n = words.size();
        int m = words[0].length();
        
        return m + solve(words, 1, words[0][0], words[0][m - 1]);
        
    }
};