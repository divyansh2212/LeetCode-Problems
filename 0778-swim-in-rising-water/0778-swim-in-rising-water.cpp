class Solution {
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool dfs(int i, int j, vector<vector<int>>& grid, vector<vector<bool>>& visited, int maxTime)
    {
        int n = grid.size();
        
        if(i < 0 || j < 0 || i == n || j == n || visited[i][j] || grid[i][j] > maxTime) return false;
            
        if(i == n - 1 && j == n - 1) return true;
        
        visited[i][j] = true;
        
        bool flag = false;
        for(int d = 0; d < 4; d++)
        {
            flag = (flag | dfs(i + dx[d], j + dy[d], grid, visited, maxTime));
            if(flag) return flag;
        }
        
        return flag;
    }
    
    bool check(vector<vector<int>>& grid, int maxTime)
    {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        return dfs(0, 0, grid, visited, maxTime);
    }
    
public:
    int swimInWater(vector<vector<int>>& grid) 
    {    
        int n = grid.size();
        int ans = -1;
        
        int lo = 0, hi = n * n - 1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(check(grid, mid))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        
        return ans;
    }
};