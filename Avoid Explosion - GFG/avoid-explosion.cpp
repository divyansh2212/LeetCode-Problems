//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class DisjointSet{
    vector<int> parent, rank;
    public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }
    
    int findPar(int node)
    {
        if(parent[node] == node) return node;
        return parent[node] = findPar(parent[node]);
    }
    
    void UnionByRank(int u, int v)
    {
        int par_u = findPar(u), par_v = findPar(v);
        if(par_u == par_v) return;
        if(rank[par_u] < rank[par_v])
            parent[par_v] = par_u;
        else if(rank[par_v] < rank[par_u])
            parent[par_u] = par_v;
        else
        {
            parent[par_u] = par_v;
            rank[par_v]++;
        }
    }
};

class Solution {
  public:
    vector<string> avoidExplosion(vector<vector<int>> mix, int n, vector<vector<int>> danger, int m) {
    
        DisjointSet ds(n + 1);
        
        vector<string> ans;
        for(int i = 0; i < n; i++)
        {
            int u = mix[i][0], v = mix[i][1];
            int par_u = ds.findPar(u), par_v = ds.findPar(v);
            
            bool flag = false;
            for(int j = 0; j < m; j++)
            {
                int x = danger[j][0], y = danger[j][1];
                int par_x = ds.findPar(x), par_y = ds.findPar(y);
                if(par_x == par_u && par_y == par_v)
                {
                    flag = true;
                    ans.push_back("No");
                    break;
                }
                else if(par_x == par_v && par_y == par_u)
                {
                    flag = true;
                    ans.push_back("No");
                    break;
                }
            }
            if(!flag)
            {
                ans.push_back("Yes");
                ds.UnionByRank(u, v);
            }
                
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mix(n, vector<int>(2));
        vector<vector<int>> danger(m, vector<int>(2));
        for (int i = 0; i < n; i++) {
            cin >> mix[i][0] >> mix[i][1];
        }

        for (int i = 0; i < m; i++) {
            cin >> danger[i][0] >> danger[i][1];
        }

        auto ans = sol.avoidExplosion(mix, n, danger, m);
        for (auto &val : ans) cout << val << " ";
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends