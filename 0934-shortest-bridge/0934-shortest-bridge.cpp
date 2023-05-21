class DisjointSet{
  
    vector<int> parent, rank;
    
    public:
    
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n, 0);
        for(int i = 0; i < n; i++)
            parent[i] = i;
    }   
    
    int find_par(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = find_par(parent[node]);
    }
    
    void unionByRank(int u, int v)
    {
        u = find_par(u);
        v = find_par(v);
        
        if(rank[u] > rank[v]){
            parent[v] = u;
        }
        else if(rank[u] < rank[v]){
            parent[u] = v;
        }
        else{
            rank[u]++;
            parent[v] = u;
        }
        
    }
    
};

class Solution {
    
    public:
    int shortestBridge(vector<vector<int>>& grid) {
      
        int n = grid.size(), m = grid[0].size();
        DisjointSet ds(n*m);
        
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                
                if(grid[i][j] == 1){
                    int id = i * m + j;
                    
                    if(i - 1 >= 0 && grid[i - 1][j] == 1){
                        int adjId = (i - 1) * m + j;
                        ds.unionByRank(id, adjId);
                    }
                    
                    if(j - 1 >= 0 && grid[i][j - 1] == 1){
                        int adjId = i * m + j - 1;
                        ds.unionByRank(id, adjId);
                    }
                    
                }           
            }
        }
        
        int ans = n * m;
        vector<pair<int, int>> island1;
        int ipar1 = -1;
        vector<pair<int, int>> island2;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    int id = i * m + j;
                    id = ds.find_par(id);
                    if(ipar1 == -1 || id == ipar1){
                        ipar1 = id;
                        island1.push_back({i, j});
                    }
                    else{
                        island2.push_back({i, j});
                    }   
                }
            }
        }
        
        for(auto &id1 : island1){
            for(auto id2 : island2){
                int x1 = id1.first, y1 = id1.second, x2 = id2.first, y2 = id2.second;
                ans = min(ans, abs(x1 - x2) + abs(y1 - y2) - 1);
            }
        }
        
        return ans;
    }
};