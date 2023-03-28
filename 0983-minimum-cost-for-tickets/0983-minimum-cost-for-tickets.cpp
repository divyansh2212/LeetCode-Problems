class Solution {
    
    int solve(int idx, int ticketTill, vector<int>& days, vector<int>& costs, vector<vector<int>> &dp)
    {
        if(idx == days.size())
            return 0;
        
        if(dp[idx][ticketTill] != -1)
            return dp[idx][ticketTill];
        
        if(ticketTill >= days[idx])
            return solve(idx + 1, ticketTill, days, costs, dp);
        
        int way1 = costs[0] + solve(idx + 1, days[idx], days, costs, dp);
        int way2 = costs[1] + solve(idx + 1, days[idx] + 6, days, costs, dp);
        int way3 = costs[2] + solve(idx + 1, days[idx] + 29, days, costs, dp);
        
        return dp[idx][ticketTill] = min(way1, min(way2, way3));
    }
    
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        vector<vector<int>> dp(500, vector<int> (500, -1));
        return solve(0, 0, days, costs, dp);
    }
};