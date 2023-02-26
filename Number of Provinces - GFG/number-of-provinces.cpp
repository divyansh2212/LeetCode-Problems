//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class DisjointSet{
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
      if(parent[node] == node)
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

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int n) {
        
        DisjointSet ds(n);
        // vector<vector<int>> graph(n);
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                if(adj[i][j] == 1 && i != j)
                        ds.unionByRank(i, j);
                    
        int provinces = 0;
        for(int i = 0; i < n; i++)
            if(ds.find_par(i) == i)
                provinces++;
        
        return provinces;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int V,x;
        cin>>V;
        
        vector<vector<int>> adj;
        
        for(int i=0; i<V; i++)
        {
            vector<int> temp;
            for(int j=0; j<V; j++)
            {
                cin>>x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }
        

        Solution ob;
        cout << ob.numProvinces(adj,V) << endl;
    }
    return 0;
}
// } Driver Code Ends