class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int ans = -1, sum = 0;queue<pair<int, int>> q;
        vector<vector<bool>>visited(n, vector<bool> (n, false));
        
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < n; j++)
            {
                sum += grid[i][j];
                if(grid[i][j] == 1)
                {
                    q.push({i, j});
                    visited[i][j] = true;
                }
                    
            }
        }
        
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                
                if(x + 1 < n && !visited[x + 1][y] && grid[x + 1][y] == 0)
                {
                    q.push({x + 1, y});
                    visited[x + 1][y] = true;
                }
                
                if(y + 1 < n && !visited[x][y + 1] && grid[x][y + 1] == 0)
                {
                    q.push({x, y + 1});
                    visited[x][y + 1] = true;
                }
                
                if(x - 1 >= 0 && !visited[x - 1][y] && grid[x - 1][y] == 0)
                {
                    q.push({x - 1, y});
                    visited[x - 1][y] = true;
                }
                
                if(y - 1 >= 0 && !visited[x][y - 1] && grid[x][y - 1] == 0)
                {
                    q.push({x, y - 1});
                    visited[x][y - 1] = true;
                }
                
            }
            
        }
        
        if(sum == 0 || sum == n * n)
            return -1;
        
        return ans;
    }
};