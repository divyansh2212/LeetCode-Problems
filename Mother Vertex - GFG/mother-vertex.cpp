//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution 
{
    
    void dfs(int node, vector<bool> &visited, vector<int> adj[], stack<int> &st)
    {
        visited[node] = true;
        for(auto &it : adj[node]) {
            if(!visited[it])
                dfs(it, visited, adj, st);
        }
        st.push(node);
    }
    
    public:
    //Function to find a Mother Vertex in the Graph.
	int findMotherVertex(int n, vector<int>adj[])
	{
	    vector<bool> visited(n, false);
	    stack<int> st;
	    for(int i = 0; i < n; i++) {
	        if(!visited[i])
	            dfs(i, visited, adj, st);
	    }
	    
	    for(int i = 0; i < n; i++) {
	        visited[i] = false;
	    }
	    
	    int node = st.top();
	   // st.clear();
	    dfs(node, visited, adj, st);
	    
	    for(int i = 0; i < n; i++) {
	        if(visited[i] == false)
	            return -1;
	    }
	    
	    return node;
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
		}
		Solution obj;
		int ans = obj.findMotherVertex(V, adj);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends