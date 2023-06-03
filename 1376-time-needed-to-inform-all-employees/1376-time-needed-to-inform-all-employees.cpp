class Solution {
    
    int dfs(int vtx, vector<int> graph[], vector<int>& informTime)
    {
        int ans = informTime[vtx];
        
        for(auto &child : graph[vtx])
        {
            ans = max(ans, informTime[vtx] + dfs(child, graph, informTime));
        }
        
        return ans;
    }
    
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        
        vector<int> graph[n];
        for(int i = 0; i < n; i++)
            if(manager[i] != -1)
                graph[manager[i]].push_back(i);
        
        int ans = dfs(headID, graph, informTime);
        return ans;
    }
};