//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool check(int start, int end, string &s)
    {
        while(start < end) {
            if(s[start] != s[end]) {
                return false;
            }
            start++, end--;
        }
        return true;
    }
    
    int solve(int start, int idx, string &s, vector<vector<int>> &dp)
    {
        int n = s.length();
        if(idx == n - 1) {
            if(check(start, idx, s)) {
                return 0;
            }
            return 1e8;
        }
        
        if(dp[start][idx] != -1) {
            return dp[start][idx];
        }
        
        int way1 = solve(start, idx + 1, s, dp);
        int way2 = 1e8;
        
        if(check(start, idx, s)) {
            way2 = 1 + solve(idx + 1, idx + 1, s, dp);
        }
        
        return dp[start][idx] = min(way1, way2);
    }
    
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(0, 0, str, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends