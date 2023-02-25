class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        int profit = 0;
        int prev = INT_MAX;
        
        for(int i = 0; i < n; i++)
        {
            profit = max(profit, prices[i] - prev);
            prev = min(prev, prices[i]);
        }
        
        return profit;
    }
};