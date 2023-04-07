class Solution {
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int i, int j, vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == 0)
            return;
        
        grid[i][j] = 0;
        for(int d = 0; d < 4; d++)
            dfs(i + dx[d], j + dy[d], grid);
    }
    
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        for(int j = 0; j < m; j++)
            if(grid[0][j] == 1)
                dfs(0, j, grid);
        for(int j = 0; j < m; j++)
            if(grid[n - 1][j] == 1)
                dfs(n - 1, j, grid);
        for(int i = 0; i < n; i++)
            if(grid[i][0] == 1)
                dfs(i, 0, grid);
        for(int i = 0; i < n; i++)
            if(grid[i][m - 1] == 1)
                dfs(i, m - 1, grid);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(grid[i][j] == 1)
                    ans++;
        
        return ans;
    }
};