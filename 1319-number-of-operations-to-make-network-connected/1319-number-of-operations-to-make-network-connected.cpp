
class DisjointSet{
      
        vector<int> rank, parent;
        
        public:
        DisjointSet(int n)
        {
            parent.resize(n);
            rank.resize(n, 0);
            
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
            u = find_par(u), v = find_par(v);
            if(u == v)
                return;
            
            if(rank[u] < rank[v])
                parent[u] = v;
            
            else if(rank[u] > rank[v])
                parent[v] = u;
            
            else{
                rank[v]++;
                parent[u] = v;
            }
        }
    };

class Solution {
    
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int edges = connections.size();
        if(edges < n - 1)
            return -1;
        
        DisjointSet ds(n);
        
        for(int i = 0; i < connections.size(); i++)
        {
            int u = connections[i][0], v = connections[i][1];
            ds.unionByRank(u, v);
        }
        
        int components = 0;
        for(int i = 0; i < n; i++)
            if(ds.find_par(i) == i)
                components++;
        
        return components - 1;
    }
};