class Solution {
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool isFresh(int x, int y, vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        return x >= 0 && y >= 0 && x < n && y < m && (grid[x][y] == 1);
    }
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        
        queue<pair<int, int>> q;
        int fresh = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1) {
                    fresh++;
                }
                else if(grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }
        
        int time = 0;
        while(!q.empty())
        {
            if(fresh == 0)
                return time;
            time++;
            int size = q.size();
            
            for(int i = 0; i < size; i++) {
                auto front = q.front(); q.pop();
                int x = front.first, y = front.second;
                
                for(int d = 0; d < 4; d++)
                {
                    int adjX = dx[d] + x, adjY = dy[d] + y;
                    if(isFresh(adjX, adjY, grid)) {
                        grid[adjX][adjY] = 2;
                        q.push({adjX, adjY});
                        fresh--;
                    }
                }
            }
        }
        
        if(fresh == 0)
            return time;
        
        return -1;
    }
};