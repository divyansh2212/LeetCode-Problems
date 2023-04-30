class DisjointSet{
  
    vector<int> parent, rank;
    
    public:  
    DisjointSet(int n)
    {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for(int i = 0; i <= n; i++)
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
        if(rank[u] > rank[v])
            parent[v] = u;
        else if(rank[v] > rank[u])
            parent[u] = v;
        else{
            rank[u]++;
            parent[v] = u;
        }
    }
    
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet alice(n);
        DisjointSet bob(n);
        
        int chosen = 0;
        for(int i = 0; i < edges.size(); i++){
            int type = edges[i][0], u = edges[i][1], v = edges[i][2];
            
            if(type == 3 && (alice.find_par(u) != alice.find_par(v) || bob.find_par(u) != bob.find_par(v))){
                alice.unionByRank(u, v);
                bob.unionByRank(u, v);
                chosen++;
            }
        }
        
        for(int i = 0; i < edges.size(); i++){
            int type = edges[i][0], u = edges[i][1], v = edges[i][2];
            
            if(type == 1 && alice.find_par(u) != alice.find_par(v)){
                alice.unionByRank(u, v);
                chosen++;
            }
            else if(type == 2 && bob.find_par(u) != bob.find_par(v)){
                bob.unionByRank(u, v);
                chosen++;
            }
        }
        
        for(int i = 2; i <= n; i++){
            if(alice.find_par(i) != alice.find_par(i - 1))
                return -1;
            if(bob.find_par(i) != bob.find_par(i - 1))
                return -1;
        }
        
        return edges.size() - chosen;
    }
};