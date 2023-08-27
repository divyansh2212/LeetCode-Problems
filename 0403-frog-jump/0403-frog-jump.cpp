class Solution {
    
    map<pair<int, int>, bool> dp;

    int solve(int idx, int k, vector<int>& stones)
    {
        int n = stones.size();
        if(idx == n - 1)
            return true;
        
        if(dp.find({idx, k}) != dp.end())
            return dp[{idx, k}];
        
        bool flag = false;
        
        for(int i = idx + 1; i < n; i++) {
            if(stones[i] - stones[idx] == k - 1) {
                flag |= solve(i, k - 1, stones);
            }
            else if(stones[i] - stones[idx] == k) {
                flag |= solve(i, k, stones);
            }
            else if(stones[i] - stones[idx] == k+1) {
                flag |= solve(i, k+1, stones);
            }
        }
        
        return dp[{idx, k}]=flag;
    }
    
    public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        return solve(0, 0, stones);
    }
};