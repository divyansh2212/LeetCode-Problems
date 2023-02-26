//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    void dfs(int node, vector<bool> &visited, vector<vector<int>>& adj, vector<int> &curr)
    {
        curr.push_back(node);
        visited[node] = true;
        
        for(auto &it : adj[node])
            if(!visited[it])
                dfs(it, visited, adj, curr);
    }
    
  public:
    int findNumberOfGoodComponent(int v, vector<vector<int>>& adj) {
        // code here
        vector<bool> visited(v + 1, false);
        vector<int> curr;
        int ans = 0;
        
        for(int i = 1; i <= v; i++)
        {
            if(!visited[i])
            {
                curr.clear();
                dfs(i, visited, adj, curr);
                
                bool flag = true;
                for(int j = 0; j < curr.size() && flag; j++)
                    if(adj[curr[j]].size() != curr.size() - 1)
                        flag = false;
                if(flag) ans++;
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
        int E, V;
        cin >> E >> V;
        vector<vector<int>> adj(V + 1, vector<int>());
        for (int i = 0; i < E; i++) {
            int u, v;

            cin >> u >> v;

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;

        int res = obj.findNumberOfGoodComponent(V, adj);
        cout << res << "\n";
    }
    return 0;
}
// } Driver Code Ends