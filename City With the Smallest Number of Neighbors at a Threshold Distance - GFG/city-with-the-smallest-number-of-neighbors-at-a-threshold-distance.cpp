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
        vector<vector<int>> distances;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int , int>>> pq;
        
        for(int i = 0; i < m; i++)
        {
            int u = edges[i][0], v = edges[i][1], wt = edges[i][2];
            graph[u].push_back({v, wt});
            graph[v].push_back({u, wt});
        }
        
        for(int city = 0; city < n; city++)
        {
            vector<int> dist(n, 1e8);
            dist[city] = 0;
            pq.push({0, city});
            
            while(!pq.empty())
            {
                auto front = pq.top();
                pq.pop();
                int wt = front.first, node = front.second;
                
                for(auto &it : graph[node])
                {
                    if(wt + it.second < dist[it.first])
                    {
                        dist[it.first] = wt + it.second;
                        pq.push({dist[it.first], it.first});
                    }
                }
            }
            distances.push_back(dist);
        }
        
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