//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
    
    int solve(int idx1, int idx2, string &s, string &rev, vector<vector<int>> &dp)
    {
        int n = s.length();
        if(idx1 == n || idx2 == n) {
            return 0;
        }
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(s[idx1] == rev[idx2]) {
            return 1 + solve(idx1 + 1, idx2 + 1, s, rev, dp);
        }
        else {
            int way1 = solve(idx1 + 1, idx2, s, rev, dp);
            int way2 = solve(idx1, idx2 + 1, s, rev, dp);
            
            return dp[idx1][idx2] = max(way1, way2);
        }
    }
    
  public:
    int minimumNumberOfDeletions(string s) { 
        // code here
        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        
        vector<vector<int>> dp(n, vector<int> (n, -1));
        
        return n - solve(0, 0, s, rev, dp);
    } 
};

//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        Solution obj;
        cout << obj.minimumNumberOfDeletions(S) << endl;
    }
    return 0;
}
// } Driver Code Ends