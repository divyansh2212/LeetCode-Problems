//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    
    int lps(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp)
    {
        int n = s.length();
        if(idx1 == n || idx2 == n)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(s[idx1] == t[idx2]) {
            return dp[idx1][idx2] = 1 + lps(s, t, idx1 + 1, idx2 + 1, dp);
        }
        else {
            int way1 = lps(s, t, idx1 + 1, idx2, dp);
            int way2 = lps(s, t, idx1, idx2+1, dp);
            return dp[idx1][idx2]=max(way1, way2);
        }
    }
    
  public:
    int longestPalinSubseq(string s) {
        //code here
        int n = s.length();
        
        string t = s;
        reverse(t.begin(), t.end());
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return lps(s, t, 0, 0, dp);
    }
};

//{ Driver Code Starts.

int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout << ob.longestPalinSubseq(s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends