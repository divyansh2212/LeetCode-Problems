//{ Driver Code Starts
#include<bits/stdc++.h>
const int mod=1e9+7;
using namespace std;

// } Driver Code Ends
// function to find longest common subsequence

class Solution
{
    int solve(int idx1, int idx2, string &s1, string &s2, vector<vector<int>> &dp)
    {
        int n = s1.length();
        int m = s2.length();
        if(idx1 == n || idx2 == m)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(s1[idx1] == s2[idx2]) {
            return dp[idx1][idx2] = 1 + solve(idx1 + 1, idx2 + 1, s1, s2, dp);
        }
        return dp[idx1][idx2] = max(solve(idx1 + 1, idx2, s1, s2, dp), solve(idx1, idx2 + 1, s1, s2, dp));
    }
    
    public:
    int lcs(int n, int m, string s1, string s2)
    {
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(0, 0, s1, s2, dp);
    }
};


//{ Driver Code Starts.
int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;          // Take size of both the strings as input
        string s1,s2;
        cin>>s1>>s2;        // Take both the string as input
        Solution ob;
        cout << ob.lcs(n, m, s1, s2) << endl;
    }
    return 0;
}

// } Driver Code Ends