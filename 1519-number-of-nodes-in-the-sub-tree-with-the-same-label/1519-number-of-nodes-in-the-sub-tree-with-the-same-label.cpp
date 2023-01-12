class Solution {
    
    void traversal(int vtx, vector<int> graph[], string &labels, vector<bool> &visited, vector<int> &ans, vector<int> &hsh)
    {
        visited[vtx] = true;
        
        for(auto &child : graph[vtx])
        {
            if(!visited[child])
            {
                vector<int> temp(26, 0);
                traversal(child, graph, labels, visited, ans, temp);
                for(int i = 0; i < 26; i++)
                    hsh[i] += temp[i];
            }
        }
        
        ans[vtx] = ++hsh[labels[vtx] - 'a'];   
    }
    
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        
        vector<int> ans(n, 0);
        vector<bool> visited(n, false);
        vector<int> hsh(26, 0);
        vector<int> graph[n];
        
        for(int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        traversal(0, graph, labels, visited, ans, hsh);
        
        return ans;
    }
};