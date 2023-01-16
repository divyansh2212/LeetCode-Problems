class Solution {
    
    int cost(int idx, vector<int>& days, vector<int>& costs, vector<int> &dp)
    {
        if(days.size() == idx)
            return 0;
        
        if(dp[idx] != -1)
            return dp[idx];
        
        int way1 = 1e9, way2 = 1e9, way3 = 1e9;
        
        int newIdx = upper_bound(days.begin(), days.end(), days[idx]) - days.begin();
        way1 = costs[0] + cost(newIdx, days, costs, dp);
        
        newIdx = upper_bound(days.begin(), days.end(), days[idx] + 6) - days.begin();
        way2 = costs[1] + cost(newIdx, days, costs, dp);
            
        newIdx = upper_bound(days.begin(), days.end(), days[idx] + 29) - days.begin();
        way3 = costs[2] + cost(newIdx, days, costs, dp);    
        
        return dp[idx] = min({way1, way2, way3});
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        vector<int> dp(days.size(), -1);
        return cost(0, days, costs, dp);
    }
};