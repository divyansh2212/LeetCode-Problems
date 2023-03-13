//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    const int mod = 1e9 + 7;
    
    int solve(int n, int r, vector<vector<int>> &dp)
    {
        if(r > n)
            return 0;
        if(n == r || r == 0 || n == 1)
            return 1;
        
        if(dp[n][r] != -1)
            return dp[n][r];
        
       return dp[n][r] = (solve(n - 1, r - 1, dp) + 0LL + solve(n - 1, r, dp)) % mod;    
    }
    
public:
    int nCr(int n, int r){
        if(r > n)
            return 0;
        vector<int> prev(r + 1, 0);
        
        // for(int i = 0; i <= r; i++)
        //     dp[i][i] = 1;
        // for(int i = 0; i <= n; i++)
        prev[0] = 1;
            
        for(int i = 1; i <= n; i++)
        {
            vector<int> curr(r + 1, 0);
            curr[0] = 1;
            for(int j = 1; j <= r; j++)
            {
                curr[j] = (prev[j - 1] + 0LL + prev[j]) % mod;
            }
            prev = curr;
        }
        return prev[r];
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}
// } Driver Code Ends