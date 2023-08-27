class Solution {
    
    unordered_map<int, int> dp;
    
    int solve(int idx, int target, vector<int> &psq)
    {
        if(target == 0)
            return 0;
        if(idx == psq.size())
            return 1e5;
        if(dp.find(target) != dp.end())
            return dp[target];
        int way1 = solve(idx + 1, target, psq);
        int way2 = 1e5;
        if(target >= psq[idx]) {
            way2 = 1 + solve(idx, target - psq[idx], psq);
        }
        return dp[target] = min({way1, way2, target});
    }
    
public:
    int numSquares(int n) {
        if(n <= 3) return n;
        vector<int> psq;
        for(int i = 2; i*i <= n; i++) {
            psq.push_back(i * i);
        }
        
        return solve(0, n, psq);
    }
};