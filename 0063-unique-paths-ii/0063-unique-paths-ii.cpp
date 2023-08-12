class Solution {
    
    int solve(vector<vector<int>>& grid, int i, int j, vector<vector<int>> &dp)
    {
        int n = grid.size();
        int m = grid[0].size();
        if(i == n || j == m || grid[i][j] == 1) return 0;
        if(i == n - 1 && j == m - 1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        
        int way1 = solve(grid, i + 1, j, dp);
        int way2 = solve(grid, i, j + 1, dp);
        
        return dp[i][j] = way1 + way2;
    }
    
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return solve(grid, 0, 0, dp);
    }
};