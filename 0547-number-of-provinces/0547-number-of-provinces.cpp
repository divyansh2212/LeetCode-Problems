class Solution {
    
    void dfs(int vtx, vector<vector<int>>& graph, vector<bool> &visited)
    {
        visited[vtx] = true;
        
        for(int i = 0; i < graph[vtx].size(); i++)
        {
            if(!visited[i] && graph[vtx][i])
                dfs(i, graph, visited);
        }
        
    }
    
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        
        int n = isConnected.size();
        vector<bool> visited(n, false);
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            if(visited[i] == false)
            {
                ans++;
                dfs(i, isConnected, visited);
            }
        }
        
        return ans;
    }
};