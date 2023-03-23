class Solution {
    
    void dfs(int vtx, vector<int> graph[], vector<bool> &visited)
    {
        visited[vtx] = true;
            
        for(auto &it : graph[vtx])
        {
            if(visited[it])
                continue;
            dfs(it, graph, visited);
        }
    }
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        
        if(connections.size() < n - 1)
            return -1;
        
        vector<int> graph[n];
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        int ccs = 0;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(visited[i])
                continue;
            dfs(i, graph, visited);
            ccs++;
        }
        
        return ccs - 1;
    }
};