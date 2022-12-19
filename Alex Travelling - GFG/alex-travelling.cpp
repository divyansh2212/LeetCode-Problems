//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int minimumCost(vector<vector<int>>& flights, int n, int k) {
        
        vector<pair<int, int>> graph[n + 1];
        int m = flights.size();
        for(int i = 0; i < m; i++)
        {
            int u = flights[i][0], v = flights[i][1], wt = flights[i][2];
            graph[u].push_back({v, wt});
        }
        
        vector<int> distances(n + 1, 1e9);
        distances[k] = 0;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int node = top.second, dist = top.first;
            
            for(auto &adj : graph[node])
            {
                int adjNode = adj.first, wt = adj.second;
                if(distances[adjNode] > dist + wt)
                {
                    distances[adjNode] = dist + wt;
                    pq.push({distances[adjNode], adjNode});
                }
            }
        }
        
        int maxMoney = -1;
        for(int i = 1; i <= n; i++)
            maxMoney = max(maxMoney, distances[i]);
            
        if(maxMoney == 1e9)
            return -1;
        else
            return maxMoney;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int size;
        cin >> size;
        vector<vector<int>> flights(size,vector<int>(3));
        for (int i = 0; i < size; i++) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            flights[i]=temp;
        }

        Solution ob;
        cout << ob.minimumCost(flights, n, k) << "\n";
    }
}

// } Driver Code Ends