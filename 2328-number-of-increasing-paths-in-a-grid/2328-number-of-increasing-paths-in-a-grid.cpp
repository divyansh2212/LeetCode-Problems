class Solution {
    
    const int mod = 1e9 + 7;
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool isValid(int i, int j, int di, int dj, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();   
        
        return (i + di) >= 0 && (j + dj) >= 0 && (i + di) < n && (j + dj) < m && grid[i + di][j + dj] > grid[i][j];
    }
    
    int solve(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {   
        if(dp[i][j] != -1)
            return dp[i][j];
        int ans = 1;
        for(int d = 0; d < 4; d++)
            if(isValid(i, j, dx[d], dy[d], grid))
                ans = (ans + solve(i + dx[d], j + dy[d], grid, dp)) % mod;
        
        return dp[i][j] = ans;
    }
    
public:
    int countPaths(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        int ans = 0;
        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                ans = (ans+0LL+solve(i, j, grid, dp)) % mod;
        
        return ans;
    }
};