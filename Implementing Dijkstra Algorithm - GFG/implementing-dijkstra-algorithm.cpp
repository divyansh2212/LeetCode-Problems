//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int n, vector<vector<int>> adj[], int src)
    {
        // Code here
        vector<int> distances(n, 1e9);
        distances[src] = 0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, src});
        
        while(!pq.empty()) {
            auto front = pq.top();
            pq.pop();
            int wt = front[0], node = front[1];
            
            for(auto &it : adj[node]) {
                int adjNode = it[0], adjWt = it[1];
                if(wt + adjWt < distances[adjNode]) {
                    distances[adjNode] = wt + adjWt;
                    pq.push({distances[adjNode], adjNode});
                }
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(distances[i] == 1e9)
                distances[i] = -1;
        }
        
        return distances;
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends