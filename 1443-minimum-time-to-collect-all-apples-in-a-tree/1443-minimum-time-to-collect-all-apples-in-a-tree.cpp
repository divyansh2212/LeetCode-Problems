class Solution {
    
    bool traversal(int vtx, vector<int> graph[], vector<bool> &hasApple, vector<bool> &visited)
    {
        visited[vtx] = true;
        
        for(auto &child: graph[vtx])
        {
            if(visited[child] == false)
            {
                if(traversal(child, graph, hasApple, visited))
                    hasApple[vtx] = true;
            }
        }
        
        return hasApple[vtx];
    }
    
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<int> graph[n];
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n, false);
        traversal(0, graph, hasApple, visited);
        
        int cost = 0;
        for(int i = 1; i < n; i++)
            if(hasApple[i])
                cost += 2;
        return cost;
    }
};