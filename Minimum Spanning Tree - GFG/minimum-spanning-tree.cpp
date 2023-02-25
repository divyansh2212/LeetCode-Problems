//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int v, vector<vector<int>> adj[])
    {
        // code here
        vector<bool> mstVisited(v, false);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0});
        int totalCost = 0;
        
        while(!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            int dis = top[0], node = top[1];
            
            if(mstVisited[node] == false)
            {
                totalCost += dis;
                mstVisited[node] = true;
                for(auto &it : adj[node])
                {
                    int childNode = it[0], wt = it[1];
                    if(!mstVisited[childNode])
                        pq.push({wt, childNode});
                }
            }
        }
        
        return totalCost;
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