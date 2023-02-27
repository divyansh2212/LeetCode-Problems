//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

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
      if(node == parent[node])
        return node;
    return parent[node] = find_par(parent[node]);
  }
  
  void unionByRank(int u, int v)
  {
      int par_u = find_par(u), par_v = find_par(v);
      if(rank[par_u] < rank[par_v])
          parent[par_u] = par_v;
      else if(rank[par_u] > rank[par_v])
          parent[par_v] = par_u;
        else {
            rank[par_u]++;
            parent[par_v] = par_u;
        }
  }
    
};

class Solution {
  public:
    int Solve(int n, vector<vector<int>>& edge) {
        // code here
        DisjointSet ds(n);
        int extra = 0;
        
        for(int i = 0; i < edge.size(); i++)
        {
            int u = edge[i][0], v = edge[i][1];
            if(ds.find_par(u) == ds.find_par(v))
                extra++;
            else
                ds.unionByRank(u, v);
        }
        
        int ccs = 0;
        for(int i = 0; i < n; i++)
            if(i == ds.find_par(i))
                ccs++;
                
        if(extra >= ccs - 1)
            return ccs - 1;
        else
            return -1;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 2; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution Obj;
        cout << Obj.Solve(n, adj) << "\n";
    }
    return 0;
}
// } Driver Code Ends