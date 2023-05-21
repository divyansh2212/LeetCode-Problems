class DisjointSet{
    vector<int> parent;
    vector<int> size;
    
    public:
    
    DisjointSet(int n){
        parent.resize(n, 0);
        size.resize(n, 1);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }
    
    int find_par(int node){
        if(node == parent[node])
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void unionBySize (int u, int v){
        u = find_par(u), v = find_par(v);
        if(u == v)
            return;
        
        if(size[u] > size[v]){
            parent[v] = u;
            size[u] += size[v];
        }
        else{
            parent[u] = v;
            size[v] += size[u];
        }
    }
    
    int find_size(int id) {
        return size[id];
    }
    
};

class Solution {
    
    bool isValid (int x, int y, int n)
    {
        return x >= 0 && y >= 0 && x < n && y < n;
    }
    
public:
    int largestIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        vector<int> dx = {-1, 0, 1, 0};
        vector<int> dy = {0, 1, 0, -1};
        DisjointSet ds(n*n);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    
                    int id = (n * i) + j;
                    
                    if(i - 1 >= 0 && grid[i - 1][j] == 1) {
                        int adjId = (n * (i - 1)) + j;
                        ds.unionBySize(id, adjId);
                    }
                    if(j - 1 >= 0 && grid[i][j - 1] == 1) {
                        int adjId = (n * i) + j - 1;
                        ds.unionBySize(id, adjId);
                    }
                }
            }
        }
        
        int maxAns = 0;
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) {
                    
                    set<int> uniqueParents;
                    for(int d = 0; d < 4; d++) {
                        int x = i + dx[d], y = j + dy[d];
                        if(isValid(x, y, n) && grid[x][y]) {
                            int id = x * n + y;
                            uniqueParents.insert(ds.find_par(id));
                        }
                    }
                    
                    int curr = 1;
                    for(auto &it : uniqueParents) {
                        curr += ds.find_size(it);
                    }
                    
                    maxAns = max(maxAns, curr);
                }
                else {
                    int id = (n * i) + j;
                    maxAns = max(maxAns, ds.find_size(id));
                }
            }
        }
        
        return maxAns;
    }
};