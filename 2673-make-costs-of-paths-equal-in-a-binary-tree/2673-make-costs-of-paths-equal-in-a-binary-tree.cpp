class Solution {
    
    int solve(int idx, int &ans, vector<int>& cost)
    {
        int n = cost.size();
        if(idx > n)
            return 0;
        int left = solve(2*idx, ans, cost);
        int right = solve((2*idx)+1, ans, cost);
        ans = ans + abs(left - right);
        return cost[idx - 1] + max(left, right);
    }
    
public:
    int minIncrements(int n, vector<int>& cost) {
        int ans = 0;
        solve(1, ans, cost);
        return ans;
    }
};