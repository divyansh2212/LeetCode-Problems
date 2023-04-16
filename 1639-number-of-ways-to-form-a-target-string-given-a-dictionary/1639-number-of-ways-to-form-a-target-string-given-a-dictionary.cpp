class Solution
{
    const int mod = 1e9 + 7;
    
    long solve(int idx1, int idx2, vector<vector<int>> &wordsFreq, string &target, vector<vector<int>> &dp)
    {
        int n = wordsFreq.size(), m = target.length();
        if(idx1 == m)
            return 1;
        if(idx2 == n)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        long way1 = solve(idx1, idx2 + 1, wordsFreq, target, dp);
        long way2 = 0;
        
        int freq = wordsFreq[idx2][target[idx1] - 'a'];
        // while(freq--)
        if(freq)
            way2 = solve(idx1 + 1, idx2 + 1, wordsFreq, target, dp);
        
        way2 = way2 * freq;
        
        return dp[idx1][idx2] = (way1 + way2) % mod;
    }
    
public:
    int numWays(vector<string>& words, string target) {
        int n = words.size(), m = words[0].length();
        vector<vector<int>> wordsFreq(m, vector<int> (26, 0));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                wordsFreq[j][words[i][j] - 'a']++;
            }
        }
        vector<vector<int>> dp(target.length(), vector<int> (m, -1));
        
        return solve(0, 0, wordsFreq, target, dp);
    }
};