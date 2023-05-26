//{ Driver Code Starts
// Initial Template for C++


#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    
    const int mod = 1e9 + 7;
    
    int solve(int n, int &x, int num, vector<vector<int>> &dp)
    {
        if(n == 0)
            return 1;
        if(pow(num, x) > n)
            return 0;
            
        if(dp[n][num] != -1)
            return dp[n][num];

        int way1 = solve(n, x, num + 1, dp);
        int way2 = solve(n - pow(num, x), x, num + 1, dp);
            
        return dp[n][num] = (way1 + 0LL + way2) % mod;
    }
    
    public:
    int numOfWays(int nn, int x)
    {
        vector<vector<int>> dp(nn + 1, vector<int> (nn + 10, -1));
        return solve(nn, x, 1, dp);
        
        // for(int j = 0; j <= nn; j++)
        //     dp[0][j] = 1;
            
        // for(int n = 1; n <= nn; n++)
        // {
        //     for(int num = nn; num >= 1; num--)
        //     {
        //         int way = 0;
        //         for(int i = num; i <= n; i++)
        //         {
        //             if(pow(i, x) <= n)
        //                 way = (way + 0LL + dp[n - pow(i, x)][i + 1]) % mod;
        //             else
        //                 break;
        //         }
                    
        //         dp[n][num] = way;
        //     }
        // }
        
        // return dp[nn][1];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int  n, x;
        cin >> n >> x;
        Solution ob;
        cout<<ob.numOfWays(n, x)<<endl;
    }
    return 0;
}

// } Driver Code Ends