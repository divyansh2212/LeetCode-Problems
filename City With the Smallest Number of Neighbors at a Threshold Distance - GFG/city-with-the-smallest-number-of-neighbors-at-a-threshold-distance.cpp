//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges, int threshold) 
    {
        vector<pair<int, int>> graph[n];
        vector<vector<long long>> distances(n, vector<long long> (n, 1e18));
        for(int i = 0; i < n; i++)
            distances[i][i] = 0;
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            if(distances[u][v] > wt)
                distances[u][v] = wt;
            if(distances[v][u] > wt)
                distances[v][u] = wt;
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        
        for(int via = 0; via < n; via++)
            for(int i = 0; i < n; i++)
                for(int j = 0; j < n; j++)
                    distances[i][j] = min(distances[i][j], distances[i][via] + distances[via][j]);
        
        int city = -1, minmCnt = n + 1;
        
        for(int i = 0; i < n; i++)
        {
            int curr = 0;
            for(int j = 0; j < n; j++)
                if(distances[i][j] <= threshold)
                    curr++;
            if(curr <= minmCnt)
                minmCnt = curr, city = i;
        }
        
        return city;
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
        // n--;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        int dist;
        cin >> dist;
        Solution obj;
        cout << obj.findCity(n, m, adj, dist) << "\n";
    }
}

// } Driver Code Ends