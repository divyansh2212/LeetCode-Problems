class Solution {
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool isSafe(int i, int j, vector<vector<bool>> &visited, int &n)
    {
        return i >= 0 && i < n && j >= 0 && j < n && (visited[i][j] == false);
    }
    
    int generatePath(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp)
    {
        int n = grid.size();
        if(i == n - 1 && j == n - 1) {
            return grid[i][j];
        }
        if(dp[i][j] != 1e9) {
            return dp[i][j];
        }
        int way1 = -1, way2 = -1;
        if(i + 1 < n)
            way1 = min(grid[i][j], generatePath(i + 1, j, grid, dp));
        if(j + 1 < n)
            way2 = min(grid[i][j], generatePath(i, j + 1, grid, dp));
        
        return dp[i][j] = max(way1, way2);
    }
    
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<vector<int>> closeTheif(n, vector<int> (n, 0));
        vector<vector<bool>> visited(n, vector<bool> (n, false));
        queue<pair<int, int>> q; // theives
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j]) {
                    q.push({i, j});
                    visited[i][j] = 1;
                }
            }
        }
        
        int dist = 0;
        while(!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++) 
            {
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                closeTheif[x][y] = dist;
                
                for(int d = 0; d < 4; d++) {
                    if(isSafe(x + dx[d], y + dy[d], visited, n)) {
                        visited[x + dx[d]][y + dy[d]] = true;
                        q.push({x + dx[d], y + dy[d]});
                    }
                }
                
            }
            dist++;
        }
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                visited[i][j] = false;
            }
        }
        
        priority_queue<vector<int>> pq;
        pq.push({closeTheif[0][0], 0, 0});
        visited[0][0] = 1;
        
        while(!pq.empty())
        {
            auto top = pq.top(); pq.pop();
            int safeness = top[0], x = top[1], y = top[2];
            
            if(x == n - 1 && y == n - 1)
                return safeness;
            
            for(int d = 0; d < 4; d++) {
                if(isSafe(x + dx[d], y + dy[d], visited, n)) {
                    visited[x + dx[d]][y + dy[d]] = 1;
                    pq.push({min(safeness, closeTheif[x + dx[d]][y + dy[d]]), x + dx[d], y + dy[d]});
                }
            }
        }
        
        return 0;
    }
};