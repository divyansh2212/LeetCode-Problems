class DisjointSet   {
    private:
    vector<int> rank, parent;
    
    public:    
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }
    
    int find_par(int node)
    {
        if(parent[node] == node)
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void unionByRank(int u, int v)
    {
        u = find_par(u), v = find_par(v);
        if(u == v)
            return;
        if(rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if(rank[v] < rank[u])
        {
            parent[v] = u;
        }
        else
        {
            rank[u]++;
            parent[v] = u;
        }
    }

};

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        DisjointSet ds(n);
        
        for(int i = 0; i < roads.size(); i++)
        {
            int a = roads[i][0], b = roads[i][1], dis = roads[i][2];
            
            if(ds.find_par(a) != ds.find_par(b))
                ds.unionByRank(a, b);
        }
        
        int u_par = ds.find_par(1);
        
        int ans = 1e5;
        for(int i = 0; i < roads.size(); i++)
        {
            int a = roads[i][0], b = roads[i][1], dis = roads[i][2];
            if(ds.find_par(a) == u_par || ds.find_par(b) == u_par)
                ans = min(ans, dis);
        }
        
        return ans;
    }
};