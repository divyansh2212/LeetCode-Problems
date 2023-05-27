class Solution {
    
    int solve(int idx, vector<int> &arr, int turn, vector<vector<int>> &dp)
    {
        int n = arr.size();
        if(idx == n)
            return 0;
        
        if(dp[idx][turn] != -1)
            return dp[idx][turn];
        
        if(turn)
        {
            int way1 = INT_MIN, way2 = INT_MIN, way3 = INT_MIN;
            way1 = arr[idx] + solve(idx + 1, arr, 0, dp);
            if(idx + 1 < n)
                way2 = arr[idx] + arr[idx + 1] + solve(idx + 2, arr, 0, dp);
            if(idx + 2 < n)
                way3 = arr[idx] + arr[idx + 1] + arr[idx + 2] + solve(idx + 3, arr, 0, dp);
            
            return dp[idx][turn] = max({way1, way2, way3});
        }
        
        else
        {
            int way1 = INT_MAX, way2 = INT_MAX, way3 = INT_MAX;
            way1 = solve(idx + 1, arr, 1, dp);
            if(idx + 1 < n)
                way2 = solve(idx + 2, arr, 1, dp);
            if(idx + 2 < n)
                way3 = solve(idx + 3, arr, 1, dp);
            
            return dp[idx][turn] = min({way1, way2, way3});
        }
    }
    
public:
    string stoneGameIII(vector<int>& stoneValue) {
        
        int n = stoneValue.size();
        int total = 0;
        
        for(int i = 0; i < n; i++) total += stoneValue[i];
        
        vector<vector<int>> dp(n, vector<int> (2, -1));
        int aliceStones = solve(0, stoneValue, 1, dp);
        int bobStones = total - aliceStones;
        
        if(aliceStones == bobStones)
            return "Tie";
        else if(aliceStones > bobStones)
            return "Alice";
        else
            return "Bob";
    }
};