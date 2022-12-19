class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        vector<int> graph[n];
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        queue<int> q;
        vector<bool> visited(n, false);
        visited[source] = true;
        q.push(source);
        
        while(!q.empty())
        {
            int front = q.front();
            q.pop();
            if(front == destination)
                return true;
            
            for(auto &child : graph[front])
            {
                if(!visited[child])
                {
                    q.push(child);
                    visited[child] = true;
                }
            }
        }
        return false;
    }
};