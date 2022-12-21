class Solution {
    
    bool dfs(int vtx, vector<int> adj[], vector<int> &color)
    {        
        for(auto &child : adj[vtx])
        {
            if(color[child] == color[vtx])
                return false;
            if(color[child] == -1)
            {
                color[child] = !color[vtx];
                if(dfs(child, adj, color) == false)
                    return false;
            }
        }
        return true;
    }
    
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        int m = dislikes.size();
        
        vector<int> adj[n + 1];
        for(int i = 0; i < m; i++)
        {
            int u = dislikes[i][0], v = dislikes[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> color(n + 1, -1);
        
        for(int i = 1; i <= n; i++)
        {
            if(color[i] != -1)
                continue;
            color[i] = 0;
            if(dfs(i, adj, color) == false)
                return false;
        }
            
        return true;
    }
};