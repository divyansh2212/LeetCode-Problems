class Solution {
    
    int maxStones(int idx, int m, vector<int>& piles, int turn,  vector<vector<vector<int>>> &dp)
    {
        int n = piles.size();
        if(idx == n)
            return 0;
        
        if(dp[idx][m][turn] != -1)
            return dp[idx][m][turn];
        
        if(turn)
        {
            int maxi = 0;
            int sum = 0;
            for(int tempm = 1, i = idx; tempm <= 2*m && i < n; tempm++, i++)
            {
                sum += piles[i];
                maxi = max(maxi, sum + maxStones(i + 1, max(m, tempm), piles, 0, dp));
            }
            
            return dp[idx][m][turn] = maxi;
        }
        else
        {
            int mini = INT_MAX;
            for(int tempm = 1, i = idx; tempm <= 2*m && i < n; tempm++, i++)
            {
                mini = min(mini,  maxStones(i + 1, max(m, tempm), piles, 1, dp));
            }
            
            return dp[idx][m][turn] = mini;
        }
    }
    
public:
    int stoneGameII(vector<int>& piles) {
        
        int n = piles.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int> > (2*n + 1, vector<int> (2, -1)));
        
        return maxStones(0, 1, piles, 1, dp);
    }
};