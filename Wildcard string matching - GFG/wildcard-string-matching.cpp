//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    
    bool solve(string &wild, string &pattern, int idx1, int idx2, vector<vector<int>> &dp)
    {
        int n = wild.length(), m = pattern.length();
        if(idx2 == m) {
            for(int i = idx1; i < n; i++) {
                if(wild[i] != '*')
                    return false;
            }
            return true;
        }
        if(idx1 == n)
            return false;
        
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        
        if(wild[idx1] == '?' || wild[idx1] == pattern[idx2]) {
            return dp[idx1][idx2] = solve(wild, pattern, idx1 + 1, idx2 + 1, dp);
        }
        else if(wild[idx1] == '*') {
            bool way1 = solve(wild, pattern, idx1 + 1, idx2 + 1, dp);
            bool way2 = solve(wild, pattern, idx1, idx2 + 1, dp);
            bool way3 = solve(wild, pattern, idx1+1, idx2, dp);
            return dp[idx1][idx2] = (way1 | way2 | way3);
        }
        else
            return dp[idx1][idx2] = false;
        
    }
    
    public:
    bool match(string wild, string pattern)
    {
        // code here
        int n = wild.length(), m = pattern.length();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(wild, pattern, 0, 0, dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends