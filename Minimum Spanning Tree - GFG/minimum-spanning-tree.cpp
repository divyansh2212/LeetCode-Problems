//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class DisjointSet
{
    vector<int> parent, rank;
    public:
    DisjointSet(int n)
    {
        rank.resize(n, 0);
        parent.resize(n);
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
        int par_u = find_par(u);
        int par_v = find_par(v);
        if(par_u == par_v)
            return;
        if(rank[par_u] < rank[par_v])
            parent[par_u] = par_v;
        else if(rank[par_v] < rank[par_u])
            parent[par_v] = par_u;
        else
        {
            parent[par_v] = par_u;
            rank[par_u]++;
        }
    }
    
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        DisjointSet ds(v);
        vector<vector<int>> edges;
        for(int i = 0; i < v; i++)
        {
            for(auto &it : adj[i])
            {
                int child = it[0], wt = it[1];
                edges.push_back({wt, i, child});
            }
        }
        
        sort(edges.begin(), edges.end());
        int mstWeight = 0;
        
        for(int i = 0; i < edges.size(); i++)
        {
            int wt = edges[i][0], u = edges[i][1], v = edges[i][2];
            if(ds.find_par(u) != ds.find_par(v))
            {
                ds.unionByRank(u, v);
                mstWeight += wt;
            }
        }
        
        return mstWeight;
    }
};

//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends