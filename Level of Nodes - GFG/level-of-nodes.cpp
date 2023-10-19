//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int v, vector<int> adj[], int x) 
	{
	    queue<int> q;
	    vector<bool> visited(v, false);
	    visited[0] = true;
	    q.push(0);
	    
	    int level = 0;
	    while(!q.empty())
	    {
	        int sz = q.size();
	        for(int i = 0; i < sz; i++) {
	            if(x == q.front())
	                return level;
	           for(auto &it : adj[q.front()]) {
	               if(visited[it]==false) {
	                   visited[it] = true;
	                    q.push(it);
	               }
	           }
	           q.pop();
	        }
	        level++;
	    }
	    
	    return -1;
	}
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends