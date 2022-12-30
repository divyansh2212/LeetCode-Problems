class Solution {
    
    void traversal(int node, vector<bool> &visited, vector<vector<int>>& graph, vector<vector<int>>& allPaths, vector<int> &curr)
    {
        int n = graph.size();
        visited[node] = true;
        curr.push_back(node);
        
        if(node == n - 1)
        {
            allPaths.push_back(curr);
            curr.pop_back();
            visited[node] = false;
            return;
        }
        
        for(auto &child : graph[node])
            if(!visited[child])
                traversal(child, visited, graph, allPaths, curr);
    
        curr.pop_back();
        visited[node] = false;
    }
    
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> allPaths;
        vector<int> curr;
        vector<bool> visited(n, false);
        
        
        traversal(0, visited, graph, allPaths, curr);
        
        return allPaths;
    }
};