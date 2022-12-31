class Solution {
    
    vector<int> delx = {-1, 0, 1, 0};
    vector<int> dely = {0, 1, 0, -1};
    
    int ways(int i, int j, vector<vector<int>>& grid)
    {
        int n = grid.size(), m = grid[0].size();
        
        if(i < 0 || j < 0 || i == n || j == m || grid[i][j] == -1)
            return 0;
        
        else if(grid[i][j] == 2)
        {
            for(int idx1 = 0; idx1 < n; idx1++)
                for(int idx2 = 0; idx2 < m; idx2++)
                    if(grid[idx1][idx2] == 0)
                        return 0;
            
            return 1;
        }
        
        int original = grid[i][j];
        grid[i][j] = -1;
        
        int ans = 0;
        
        for(int d = 0; d < 4; d++)
            ans += ways(i + delx[d], j + dely[d], grid);
        
        grid[i][j] = original;
        
        return ans;
    }
    
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        int startx = -1, starty = -1;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 1)
                {
                    startx = i, starty = j;
                    break;
                }
            }
        }
        
        return ways(startx, starty, grid);
    }
};