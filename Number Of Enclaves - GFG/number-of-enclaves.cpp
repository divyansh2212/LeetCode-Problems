//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int numberOfEnclaves(vector<vector<int>> &grid) {
        
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        queue<pair<int, int>> q;
        
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if((i == 0 || i == n - 1 || j == 0 || j == m - 1) && grid[i][j])
                    q.push({i, j}), visited[i][j] = true;
        
        vector<int> delx = {1, 0, -1, 0};
        vector<int> dely = {0, -1, 0, 1};
        
        while(!q.empty())
        {
            int sz = q.size();
            for(int k = 0; k < sz; k++)
            {
                auto front = q.front();
                q.pop();
                int x = front.first, y = front.second;
                // visited[x][y] = true;
                for(int i = 0; i < 4; i++)
                {
                        int idx1 = delx[i] + x, idx2 = dely[i] + y;
                        if(idx1 >= 0 && idx2 >= 0 && idx1 < n && idx2 < m && !visited[idx1][idx2] && grid[idx1][idx2])
                            q.push({idx1, idx2}), visited[idx1][idx2] = true;
                }
            }
        }
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(!visited[i][j] && grid[i][j])
                    ans++;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends