class Solution {
    
    vector<int> dx = {-1 ,0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> &visited, bool &flag)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] == 'X' || visited[i][j])
            return;
        visited[i][j] = true;
        if(i == n - 1 || j == m - 1 || i == 0 || j == 0)
            flag = false;
        
        for(int d = 0; d < 4; d++)
            dfs(i + dx[d], j + dy[d], board, visited, flag);
    }
    
    void dfs2(int i, int j, vector<vector<char>>& board, vector<vector<bool>> &visited)
    {
        int n = board.size();
        int m = board[0].size();
        
        if(i < 0 || j < 0 || i == n || j == m || board[i][j] == 'X' || visited[i][j])
            return;
        visited[i][j] = true;
        board[i][j] = 'X';
        
        for(int d = 0; d < 4; d++)
            dfs2(i + dx[d], j + dy[d], board, visited);
    }
    
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!visited[i][j] && board[i][j] == 'O') {
                    bool flag = true;
                    dfs(i, j, board, visited, flag);
                    
                    if(flag==true) {
                        vector<vector<bool>> visited2(n, vector<bool> (m, false));
                        dfs2(i, j, board, visited2);
                    }
                }
            }
        }
        
    }
};