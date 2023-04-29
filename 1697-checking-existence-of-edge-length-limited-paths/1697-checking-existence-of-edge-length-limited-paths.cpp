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
        u = find_par(u), v = find_par(v);
        if(rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else if(rank[v] > rank[u])
        {
            parent[u] = v;
        }
        else
        {
            rank[v]++;
            parent[u] = v;
        }
    }
    
};

class Solution {
    
    bool static comp(vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }
    
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        sort(edges.begin(), edges.end(), comp);
        DisjointSet ds(n);
        
        for(int i = 0; i < queries.size(); i++)
            queries[i].push_back(i);
        sort(queries.begin(), queries.end(), comp);
        int j = 0;
        
        vector<bool> ans(queries.size());
        for(int i = 0; i < queries.size(); i++)
        {
            int u = queries[i][0], v = queries[i][1], limit = queries[i][2], idx = queries[i][3];
            while(j < edges.size())
            {
                int a = edges[j][0], b = edges[j][1], wt = edges[j][2];
                if(wt < limit){
                    ds.unionByRank(a, b);
                    j++;
                }
                else
                    break;
            }
            if(ds.find_par(u) == ds.find_par(v))
                ans[idx] = true;
            else
                ans[idx] = false;
        }
        
        return ans;
    }
};