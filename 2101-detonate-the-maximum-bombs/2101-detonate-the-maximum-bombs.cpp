class DisjointSet{

    vector<int> parent;
    vector<int> size;
    
    public:
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find_par(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void unionBySize(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        if(u == v)
            return;
        
        if(size[u] > size[v])
        {
            size[u] += size[v];
            parent[v] = u;
        }
        else
        {
            size[v] += size[u];
            parent[u] = v;
        }
    }
    
};

class Solution {
    
    void dfs(int i, vector<vector<int>>& bombs, vector<bool> &visited)
    {
        int n = bombs.size();
        visited[i] = true;
        long x1 = bombs[i][0], y1 = bombs[i][1], r1 = bombs[i][2];
        
        for(int j = 0; j < n; j++)
        {
            if(!visited[j])
            {
                long x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                if((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) <= r1*r1)
                    dfs(j, bombs, visited);
            }
        }
        
    }
    
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        
        int n = bombs.size();
        int maxBombs = 0;
        
        for(int i = 0; i < n; i++)
        {
            vector<bool> visited(n, false);
            dfs(i, bombs, visited);
            int count = 0;
            for(int j = 0; j < n; j++)
                if(visited[j])
                    count++;
            
            maxBombs = max(maxBombs, count);
        }
        
        return maxBombs;
    }
};