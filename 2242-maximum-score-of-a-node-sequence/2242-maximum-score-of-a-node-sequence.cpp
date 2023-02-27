class Solution {
    
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        int m = edges.size();
        vector<pair<int, int>> graph[n];
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            graph[u].push_back({scores[v], v});
            graph[v].push_back({scores[u], u});
        }
        
        for(int i = 0; i < n; i++)
        {
            sort(graph[i].begin(), graph[i].end());
            reverse(graph[i].begin(), graph[i].end()); 
        }
            
        int ans = -1;
        
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1];
            int currScore = scores[u] + scores[v];
            
            int firstMax = -1, secondMax = -1, firstNode = -1, secondNode = -1;
            for(auto &it : graph[u])
            {
                if(it.second == v)
                    continue;
                firstMax = it.first;
                firstNode = it.second;
                break;
            }
            
            for(auto &it : graph[v])
            {
                if(it.second == u || it.second == firstNode)
                    continue;
                secondMax = it.first;
                secondNode = it.second;
                break;
            }
            
            if(firstMax > -1 && secondMax > -1)
                currScore += scores[firstNode] + scores[secondNode];
            else
                continue;
            
            ans = max(ans, currScore);
        }
        
        for(int i = 0; i < m; i++)
        {
            int v = edges[i][0], u = edges[i][1];
            int currScore = scores[u] + scores[v];
            
            int firstMax = -1, secondMax = -1, firstNode = -1, secondNode = -1;
            for(auto &it : graph[u])
            {
                if(it.second == v)
                    continue;
                firstMax = it.first;
                firstNode = it.second;
                break;
            }
            
            for(auto &it : graph[v])
            {
                if(it.second == u || it.second == firstNode)
                    continue;
                secondMax = it.first;
                secondNode = it.second;
                break;
            }
            
            if(firstMax > -1 && secondMax > -1)
                currScore += scores[firstNode] + scores[secondNode];
            else
                continue;
            
            ans = max(ans, currScore);
        }
        
        return ans;
    }
};