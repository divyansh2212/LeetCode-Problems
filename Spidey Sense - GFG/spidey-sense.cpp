//{ Driver Code Starts

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
    
    int solve(int i, int j, vector<vector<char>> &building, int &n, int &m, vector<vector<bool>> &visited)
    {
        queue<vector<int>> q;
        q.push({i, j});
        
        int ans = 0;
        while(!q.empty())
        {
            ans++;
            int sz = q.size();
            for(int i = 0; i < sz; i++)
            {
                auto front = q.front();
                q.pop();
                int x = front[0], y = front[1];
                if(x < 0 || y < 0 || x == n || y == m || visited[x][y] || building[x][y] == 'W')
                    continue;
                if(building[x][y] == 'B')
                    return ans - 1;
                visited[x][y] = true;
                q.push({x - 1, y});
                q.push({x, y - 1});
                q.push({x + 1, y});
                q.push({x, y + 1});
            }
        }
        
        return 1e6;
    }
    
  public:
    vector<vector<int>> findDistance(vector<vector<char>> &building, int n, int m) {
        // code her
        vector<vector<int>> ans(n, vector<int> (m));
        // vector<vector<int>> dp(n, vector<int> (m, -1));
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(building[i][j] == 'O')
                {
                    vector<vector<bool>> visited(n, vector<bool> (m, false));
                    int distance = solve(i, j, building, n, m, visited);
                    if(distance >= 1e6)
                        distance = -1;
                    ans[i][j] = distance;
                }
                else if(building[i][j] == 'W')
                    ans[i][j] = -1;
                else
                    ans[i][j] = 0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{

    int t;
    cin >> t;
    while(t--)
    {
    	int M,N;
        cin>>M;
        cin>>N;

        vector<vector<char> > matrix(M);
        for(int i=0; i<M; ++i)
        {
            matrix[i].resize(N);
            for (int j = 0; j < N; ++j)
                cin>>matrix[i][j];
        }

        vector<vector<int> >result;
        Solution obj;
        result = obj.findDistance(matrix, M,N); 
        for(int i=0; i<M; ++i)
        {
            for (int j = 0; j < N; ++j)
                cout<<result[i][j]<<" ";
            cout<<"\n";
        }
    }

    return 0;
}
// } Driver Code Ends