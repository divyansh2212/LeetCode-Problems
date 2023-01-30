//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{
    
    vector<int> visited;
    int ans = 0;
    
    bool dfs(vector<int> graph[], int vtx)
    {
        visited[vtx] = true;
        
        bool select = false;
        for(auto &child : graph[vtx])
        {
            if(!visited[child])
            {
                if(dfs(graph, child) == false)
                    select = true;
            }
        }
        
        if(select)
            ans++;
        
        return select;
    }
    
  public:
    int countVertex(int n, vector<vector<int>>edges){
        
        vector<int> graph[n + 1];
        
        visited = vector<int> (n + 1, 0);
        
        for(auto &ele : edges)
        {
            int u = ele[0], v = ele[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        dfs(graph, 1);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        vector<vector<int>>edges;
        for(int i = 0; i < N-1; i++){
            int x,y;
            cin >> x >> y;
            vector<int> edge;
            edge.push_back(x);
            edge.push_back(y);
            edges.push_back(edge);
        }
        
        Solution ob;
        cout << ob.countVertex(N, edges) << endl;
    }
    return 0; 
} 
// } Driver Code Ends