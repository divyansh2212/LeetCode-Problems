//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    bool dfs(int vtx, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited)
    {
        visited[vtx] = true, pathVisited[vtx] = true;
        
        for(auto &child : adj[vtx])
        {
            if(!visited[child])
            {
                if(dfs(child, adj, visited, pathVisited))
                    return true;
            }
            else if(pathVisited[child])
                return true;
        }
        
        pathVisited[vtx] = false;
        return false;
    }
    
  public:
    vector<int> eventualSafeNodes(int v, vector<int> adj[]) {
        
        vector<bool> visited(v, false), pathVisited(v, false);
        vector<int> ans;
        
        for(int i = 0; i < v; i++)
        {
            if(!visited[i])
                dfs(i, adj, visited, pathVisited);
        }
        
        for(int i = 0; i < v; i++)
            if(pathVisited[i] == 0)
                ans.push_back(i);
        
        return ans;
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int V, E;
        cin >> V >> E;
        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<int> safeNodes = obj.eventualSafeNodes(V, adj);
        for (auto i : safeNodes) {
            cout << i << " ";
        }
        cout << endl;
    }
}

// } Driver Code Ends