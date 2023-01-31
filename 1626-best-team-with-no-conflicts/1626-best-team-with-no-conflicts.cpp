class Solution {
    
    int bestScore(int idx, int last, vector<pair<int, int>> &pairs, vector<vector<int>> &dp)
    {
        int n = pairs.size();
        if(idx == n)
            return 0;
        
        if(dp[idx][last + 1] != -1)
            return dp[idx][last + 1];
        
        int way1 = bestScore(idx + 1, last, pairs, dp);
        int way2 = 0;
        
        if(last == -1)
            way2 = pairs[idx].second + bestScore(idx + 1, idx, pairs, dp);
        else
        {
            if(pairs[idx].first == pairs[last].first)
                way2 = pairs[idx].second + bestScore(idx + 1, idx, pairs, dp);
            else if(pairs[last].second <= pairs[idx].second)
                way2 = pairs[idx].second + bestScore(idx + 1, idx, pairs, dp);
        }
        
        return dp[idx][last + 1] = max(way1, way2);
    }
    
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        
        vector<pair<int, int>> pairs;
        for(int i = 0; i < n; i++)
            pairs.push_back({ages[i], scores[i]});
        
        sort(pairs.begin(), pairs.end());
        
        vector<vector<int>> dp(n, vector<int> (n + 1, -1));
        
        return bestScore(0, -1, pairs, dp);
    }
};