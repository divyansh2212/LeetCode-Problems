class Solution {
    
    void dfs(int node, vector<int> graph[], vector<bool> &visited)
    {
        visited[node] = true;
        
        for(auto &child : graph[node])
            if(visited[child] == false)
                dfs(child, graph, visited);
    }
    
    void dfs(int node, vector<int> graph[], vector<int> &topo, vector<bool> &visited)
    {
        visited[node] = true;
        
        for(auto &child : graph[node])
            if(visited[child] == false)
                dfs(child, graph, topo, visited);
        
        topo.push_back(node);
    }
    
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        vector<int> graph[n];
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
        }
        
        vector<int> topo;
        vector<bool> visited(n, false);
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                dfs(i, graph, topo, visited);
            }
        }
        
        reverse(topo.begin(), topo.end());
        
        for(int i = 0; i < n; i++) visited[i] = false;
        
        vector<int> ans;
        for(int i = 0; i < topo.size(); i++)
        {
            if(!visited[topo[i]])
            {
                // cout << topo[i] << " ";
                ans.push_back(topo[i]);
                dfs(topo[i], graph, visited);
            }
        }
        
        return ans;
    }
};