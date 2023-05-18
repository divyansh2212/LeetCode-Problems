//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    bool checkIsland(int i, int j, vector<vector<int>>& matrix, vector<vector<bool>> &visited)
    {
        int n = matrix.size(), m = matrix[0].size();
        
        if(i < 0 || j < 0 || i == n || j == m || matrix[i][j] == 0 || visited[i][j] == true)
            return true;
        if(i == n - 1 || j == m - 1 || i == 0 || j == 0)
            return false;
            
        visited[i][j] = true;
        bool flag = true;
        
        for(int d = 0; d < 4; d++)
        {
            flag = (flag & checkIsland(i + dx[d], j + dy[d], matrix, visited));
        }
        
        return flag;
    }
    
    public:
    int closedIslands(vector<vector<int>>& matrix, int n, int m) {
        // Code here
        int ans = 0;
        vector<vector<bool>> visited(n, vector<bool> (m, false));
        
        for(int i = 1; i < n - 1; i++)
        {
            for(int j = 1; j < m - 1; j++)
            {
                if(visited[i][j] == false && matrix[i][j] == 1 && checkIsland(i, j, matrix, visited))
                    ans++;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
        int N, M;
        cin >> N >> M;
        vector<vector<int>>matrix(N, vector<int>(M, 0));
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                cin >> matrix[i][j];
                
        Solution obj;
        int ans = obj.closedIslands(matrix, N, M);
        cout << ans << "\n";
    }
	
	return 0;
	
}


// } Driver Code Ends