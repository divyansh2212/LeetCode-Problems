//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{  
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int i, int j, vector<vector<int>> &mat, int &n, int &m, vector<vector<bool>> &visited)
    {
        visited[i][j] = true;
            
        for(int d = 0; d < 4; d++)
        {
            int x = dx[d] + i, y = dy[d] + j;
            
            if(x >= 0 && x < n && y >= 0 && y < m && !visited[x][y] && mat[x][y] >= mat[i][j])
                dfs(x, y, mat, n, m, visited);
        }
    }
    
public:
    int water_flow(vector<vector<int>> &mat, int n, int m){
    // Write your code here.
    
        int ans = 0;
        
        vector<vector<bool>> indian(n, vector<bool> (m, false));
        vector<vector<bool>> arab(n, vector<bool> (m, false));
        
        for(int j = 0; j < m; j++)
            dfs(0, j, mat, n, m, indian);
        for(int i = 0; i < n; i++)
            dfs(i, 0, mat, n, m, indian);
        for(int i = 0; i < n; i++)
            dfs(i, m - 1, mat, n, m, arab);
        for(int j = 0; j < m; j++)
            dfs(n - 1, j, mat, n, m, arab);
            
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(arab[i][j] && indian[i][j])
                    ans++;
        
        return ans;
    }
};



//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                cin>>mat[i][j];
            }
        }
        Solution ob;
        cout << ob.water_flow(mat, n, m) << endl;
        
    }
}


// } Driver Code Ends