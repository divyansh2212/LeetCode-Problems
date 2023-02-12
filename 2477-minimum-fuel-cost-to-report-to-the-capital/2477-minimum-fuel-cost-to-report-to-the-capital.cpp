class Solution {
    long long ans = 0;
    
    long long cost(int node, int &seats, vector<int> graph[], int &n, vector<bool> &visited)
    {
        visited[node] = true;
        long long cnt = 1;
        
        for(auto &child : graph[node])
            if(!visited[child])
                cnt += cost(child, seats, graph, n, visited);
        
        long long x = cnt / seats;
        
        if(cnt % seats)
            x++;
        
        if(node != 0)
            ans += x;
        
        
        return cnt;
        // return ceil(((ans + 1)*1.0) / seats);
    }
    
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> graph[n + 1];
        
        for(int i = 0; i < n; i++)
        {
            int u = roads[i][0], v = roads[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        vector<bool> visited(n + 1, false);
        
        ans = 0;
        
        cost(0, seats, graph, n, visited);
        
        return ans;
    }
};