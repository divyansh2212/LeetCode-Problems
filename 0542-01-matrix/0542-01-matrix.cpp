class Solution {
    
    vector<int> dx = {1, 0, -1, 0};
    vector<int> dy = {0, -1, 0, 1};
    
    bool isValid(int i, int j, int &n, int &m)
    {
        return i >= 0 && j >= 0 && i < n && j < m;
    }
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> distances(n, vector<int> (m, 0));
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        
        queue<vector<int>> q;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j, 0});
                    visited[i][j] = true;
                }
            }
        }
        
        while(!q.empty())
        {
            auto front = q.front(); q.pop();
            int x = front[0], y = front[1], dist = front[2];
            distances[x][y] = dist;
            
            for(int d = 0; d < 4; d++) {
                int adjX = x + dx[d], adjY = y + dy[d];
                if(isValid(adjX, adjY, n, m) && !visited[adjX][adjY]) {
                    q.push({adjX, adjY, dist + 1});
                    visited[adjX][adjY] = true;
                }
            }
        }
        
        return distances;
    }
};