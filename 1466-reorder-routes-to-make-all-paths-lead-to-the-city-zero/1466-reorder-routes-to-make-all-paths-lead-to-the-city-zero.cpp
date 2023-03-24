class Solution {
public:
    int minReorder(int n, vector<vector<int>>& edges) {
        
        int m = edges.size();
        
        vector<pair<int, int>> graph[n];
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back({v, 1});
            graph[v].push_back({u, 0});
        }
        
        vector<bool> visited(n, false);
        int cost = 0;
        queue<int> q;
        q.push(0);
        
        while(!q.empty())
        {
            int size = q.size();
            for(int i = 0; i < size; i++)
            {
                auto front = q.front(); q.pop();
                visited[front] = true;
                
                for(auto &it : graph[front])
                {
                    int child = it.first, c = it.second;
                    if(!visited[child])
                    {
                        q.push(child);
                        cost += c;
                    }
                }
            }
        }
        
        return cost;
    }
};