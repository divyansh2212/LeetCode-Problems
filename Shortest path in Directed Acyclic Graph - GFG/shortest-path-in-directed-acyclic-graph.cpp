//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
     vector<int> shortestPath(int n, int m, vector<vector<int>>& edges){
        vector<pair<int, int>> adj[n];
        vector<int> distances(n, 1e9);
        priority_queue<pair<int, int>> pq;
        
        for(int i = 0; i < m; i++) {
            int u = edges[i][0], v = edges[i][1], dist = edges[i][2];
            adj[u].push_back({v, dist});
        }
        pq.push({0, 0});
        distances[0] = 0;
        
        while(!pq.empty())
        {
            auto front = pq.top(); pq.pop();
            int node = front.second, wt = front.first;
            
            for(auto &it : adj[node]) {
                int adjNode = it.first, adjWt = it.second;
                if(distances[adjNode] > adjWt + wt) {
                    distances[adjNode] = adjWt + wt;
                    pq.push({distances[adjNode], adjNode});
                }
            }
        }
        
        
        for(int i = 0; i < n; i++) if(distances[i] == 1e9) distances[i] = -1;
        
        return distances;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends