class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<pair<int, double>> graph[n];
        vector<double> distances(n, 0);
        priority_queue<pair<double, int>> pq;
        vector<bool> visited(n, false);
        
        for(int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back({v, succProb[i]});
            graph[v].push_back({u, succProb[i]});
        }
        
        distances[start] = 1.0;
        pq.push({1.0, start});
         
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int node = top.second; double edgewt = top.first;
            
            if(visited[node] == false)
            {
                visited[node] = true;
            
                for(auto &child : graph[node])
                {
                    double edge = child.second;
                    if(edgewt * edge > distances[child.first]) {
                        distances[child.first] = edgewt * edge;
                        pq.push({distances[child.first], child.first});
                    }
                }
            }
            
        }
        
        return distances[end];
    }
    
};