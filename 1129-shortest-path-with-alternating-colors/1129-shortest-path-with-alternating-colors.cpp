class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        
        vector<int> distances(n, 1e9);
        distances[0] = 0;
        
        vector<pair<int, int>> graph[n];
        
        for(auto &it : redEdges)
        {
            int u = it[0], v = it[1];
            graph[u].push_back({v, 0});
        }
        for(auto &it : blueEdges)
        {
            int u = it[0], v = it[1];
            graph[u].push_back({v, 1});
        }
        
        queue<vector<int>> q;
        q.push({0, 0, -1});
        vector<vector<bool>> visited(n, vector<bool> (2, false));
        visited[0][0] = true, visited[0][1] = true;
        
        while(!q.empty())
        {
            auto front = q.front();
            q.pop();
            int node = front[0], steps = front[1], color = front[2];
            
            for(auto &child : graph[node])
            {
                int childNode = child.first, colorChild = child.second;
                
                if(colorChild != color && visited[childNode][colorChild] == false)
                {
                    visited[childNode][colorChild] = true;
                    q.push({childNode, steps + 1, colorChild});
                    if(distances[childNode] > steps + 1)
                        distances[childNode] = steps + 1;
                }
            }
        }
        
        for(int i = 0; i < n; i++)
            if(distances[i] == 1e9)
                distances[i] = -1;
        
        return distances;
    }
};