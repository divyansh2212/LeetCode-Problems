//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<bool> &pathVisited, bool &ans) {
        pathVisited[node] = true;
        visited[node] = true;
        
        for(auto &it : adj[node]) {
            if(visited[it] && pathVisited[it]) {
                ans = false;
            }
            else if(!visited[it]) {
                if(pathVisited[it])
                    ans = false;
                    else
                dfs(it, adj, visited, pathVisited, ans);
            }
        }
        
        pathVisited[node] = false;
    }
    
public:
	bool isPossible(int n, int p, vector<pair<int, int>>& prerequisites) {
	    // Code here
	    vector<int> adj[n];
	    for(int i = 0; i < p; i++) {
	        int u = prerequisites[i].first;
	        int v = prerequisites[i].second;
	        
	        adj[v].push_back(u);
	    }
	    
	    vector<bool> visited(n, false);
	    vector<bool> pathVisited(n, false);
	    bool ans = true;
	    
	    for(int i = 0; i < n; i++) {
	        if(!visited[i]) {
	            dfs(i, adj, visited, pathVisited, ans);
	        }
	    }
	    
 	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends