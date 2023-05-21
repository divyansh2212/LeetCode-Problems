class DisjointSet{
  
    vector<int> parent, size;
    
    public:
    DisjointSet (int n) {
        parent.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    
    int find_par(int node) {
        if(node == parent[node])
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void unionBySize(int u, int v) {
        u = find_par(u), v = find_par(v);
        
        if(u == v)
            return;
        
        if(size[u] > size[v]){
            size[u] += size[v];
            parent[v] = u;
        }
        else {
            size[v] += size[u];
            parent[u] = v;
        }
    }
    
    int find_size(int u)
    {
        return size[u];
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // 1 1 0
        // 1 0 1
        // 0 1 1
        int n = stones.size();
        DisjointSet ds(n);
        
        for(int i = 0; i < n; i++) {
            int x1 = stones[i][0], y1 = stones[i][1];
            for(int j = i + 1; j < n; j++) {
                int x2 = stones[j][0], y2 = stones[j][1];
                if(x1 == x2 || y1 == y2) {
                    ds.unionBySize(i, j);
                }
            }
        }
        
        int ans = 0;
        
        set<int> start;
        for(int i = 0; i < n; i++) {
            start.insert(ds.find_par(i));
            // ans = max(ans, ds.find_size(i) - 1);
        }
        
        for(auto &it : start)
            ans += ds.find_size(it) - 1;
        
        return ans;
    }
};