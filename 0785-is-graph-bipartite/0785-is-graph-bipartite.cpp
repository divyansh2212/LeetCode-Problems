class Solution {
    
    bool dfs(vector<int> &color, vector<vector<int>>& graph, int node)
    {
        for(auto &child : graph[node])
        {
            if(color[child] == -1)
            {
                color[child] = !color[node];
                if(dfs(color, graph, child) == false)
                    return false;
            }
            else if(color[child] == color[node])
                return false;
        }
        
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n = graph.size();
        vector<int> color(n, -1);
        
        for(int i = 0; i < n; i++)
        {
            if(color[i] == -1)
            {
                color[i] = 0;
                if(!dfs(color, graph, i))
                    return false;
            }
        }
        
        return true;
    }
};