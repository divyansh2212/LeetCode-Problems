//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int n, int m, vector<vector<int>> arr, int x, int y) {
        // code here
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        queue<pair<int, int>> q;
        if(arr[0][0])
            q.push({0, 0});
        visited[0][0] = true;
        int steps = 0;
        
        while (!q.empty())
        {
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front(); q.pop();
                int r = front.first, c = front.second;
                if(r == x && c == y)
                    return steps;
                if(r - 1 >= 0 && !visited[r - 1][c] && arr[r - 1][c]) {
                    q.push({r-1, c});
                    visited[r - 1][c] = true;
                }
                if(c - 1 >= 0 && !visited[r][c - 1] && arr[r][c-1]) {
                    q.push({r, c - 1});
                    visited[r][c - 1] = true;
                }
                if(r + 1 < n && !visited[r + 1][c] && arr[r + 1][c]) {
                    q.push({r+1, c});
                    visited[r + 1][c] = true;
                }
                if(c + 1 < m && !visited[r][c + 1] && arr[r][c+ 1]) {
                    q.push({r, c + 1});
                    visited[r][c + 1] = true;
                }
            }
            steps++;
        }
        
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends