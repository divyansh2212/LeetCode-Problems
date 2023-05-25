class Solution {
    
    bool dfs(int node, vector<bool> &visited, vector<bool> &pathvisited, vector<vector<int>>& graph, vector<int> &check)
    {
        visited[node] = true;
        pathvisited[node] = true;
        check[node] = 0;
        
        for(auto &child : graph[node])
        {
            if(!visited[child])
            {
                if(dfs(child, visited, pathvisited, graph, check))
                    return true;
            }
                
            else if(pathvisited[child])
                return true;
        }
        
        check[node] = 1;
        pathvisited[node] = false;
        return false;
    }
    
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        
        int n = graph.size();
        
        vector<bool> visited(n, false);
        vector<bool> pathvisited(n, false);
        vector<int> check(n, 0);
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
            if(!visited[i])
                dfs(i, visited, pathvisited, graph, check); 
        
        for(int i = 0; i < n; i++) if(check[i]) ans.push_back(i);
        
        return ans;
    }
};