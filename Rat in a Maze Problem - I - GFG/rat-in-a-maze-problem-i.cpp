//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
    void dfs(int i, int j, vector<vector<int>> &mat, vector<string> &ans, string curr)
    {
        int n = mat.size();
        
        if(i < 0 || j < 0 || i == n || j == n || mat[i][j] == 0)
            return;
        
        if(i == n - 1 && j == n - 1)
        {
            ans.push_back(curr);
            return;
        }
        
        mat[i][j] = 0;
        
        for(int d = 0; d < 4; d++)
        {
            if(dx[d] == 1)
                curr.push_back('D');
            else if(dx[d] == -1)
                curr.push_back('U');
            else if(dy[d] == 1)
                curr.push_back('R');
            else if(dy[d] == -1)
                curr.push_back('L');
            dfs(i + dx[d], j + dy[d], mat, ans, curr);
            curr.pop_back();
        }
        
        mat[i][j] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &mat, int n) {
        
        vector<string> ans;
        string curr = "";
        
        dfs(0, 0, mat, ans, curr);
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends