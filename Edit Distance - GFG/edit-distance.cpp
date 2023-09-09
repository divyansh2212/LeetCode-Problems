//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    int solve(int idx1, int idx2, string &s, string &t, vector<vector<int>> &dp)
    {
        int n = s.length(), m = t.length();
        if(idx1 == n && idx2 == m)
            return 0;
        if(idx1 == n) {
            return m - idx2;
        }
        if(idx2 == m) {
            return n - idx1;
        }
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        
            int way1 = solve(idx1 + 1, idx2 + 1, s, t, dp);
            int way2 = 1 + solve(idx1, idx2 + 1, s, t, dp);
            int way3 = 1 + solve(idx1 + 1, idx2, s, t, dp);
            
            if(s[idx1] != t[idx2])
                way1++;
            
            return dp[idx1][idx2]=min({way1, way2, way3});
    }
    
  public:
    int editDistance(string s, string t) {
        // Code here
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, s, t, dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends