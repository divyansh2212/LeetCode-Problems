class DisjointSet {
    vector<int> parent;
    vector<int> size;
    
    public:
    DisjointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        
        for(int i = 0; i < n + 1; i++)
            parent[i] = i;
    }
    
    int find_par(int x)
    {
        if(x == parent[x])
            return x;
        return parent[x] = find_par(parent[x]);
    }
    
    void unionBySize(int u, int v) {
        u = find_par(u), v = find_par(v);
        if(size[u] < size[v]) {
            size[v] += size[u];
            parent[u] = v;
        }
        else {
            size[u] += size[v];
            parent[v] = u;
        }
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisjointSet ds(n);
        vector<int> ans;
        
        for(auto &it : edges) {
            if(ds.find_par(it[0]) == ds.find_par(it[1])) {
                ans = it;
            }
            else {
                ds.unionBySize(it[0], it[1]);
            }
        }
        
        return ans;
    }
};