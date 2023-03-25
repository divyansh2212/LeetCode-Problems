class Solution {
    
    int dfs(int node, vector<int> graph[], vector<bool> &visited)
    {
        visited[node] = true;
        
        int curr = 0;
        
        for(auto &child : graph[node])
        {
            if(!visited[child])
                curr += (1 + dfs(child, graph, visited));
        }
        
        return curr;
    }
    
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long ans = 0;
        
        vector<int> graph[n];
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        
        vector<int> sizes;
        for(int i = 0; i < n; i++)
        {
            if(!visited[i])
            {
                int currSize = 1 + dfs(i, graph, visited);
                sizes.push_back(currSize);
            }
        }
        
        
        int totalNodes = n;
        
        for(int i = 0; i < sizes.size(); i++)
        {
            totalNodes -= sizes[i];
            ans += (totalNodes * 1LL * sizes[i]);
        }
        
        return ans;
    }
};