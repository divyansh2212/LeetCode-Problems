//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    
    void solve(int x, int y, vector<vector<int>> &mat, vector<string> &ans, string &curr)
    {
        int n = mat.size();
        if(x  == n || y == n || x < 0 || y < 0 || mat[x][y] == 0)
            return;
        if(x == n - 1 && y == n - 1) {
            ans.push_back(curr);
            return;
        }
        
        mat[x][y] = 0;
        curr.push_back('D');
        solve(x + 1, y, mat, ans, curr);
        curr.pop_back();
        curr.push_back('R');
        solve(x, y+1, mat, ans, curr);
        curr.pop_back();
        curr.push_back('U');
        solve(x-1, y, mat, ans, curr);
        curr.pop_back();
        curr.push_back('L');
        solve(x, y-1, mat, ans, curr);
        curr.pop_back();
        mat[x][y] = 1;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        string curr = "";
        
        solve(0, 0, m, ans, curr);
        
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