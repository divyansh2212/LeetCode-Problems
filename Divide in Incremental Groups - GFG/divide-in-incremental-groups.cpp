//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    int dp[101][101][101];
    
    int solve(int last, int n, int k)
    {
        if(k == 0 && n == 0)
            return 1;
        if(k == 0 || n == 0)
            return 0;
        
        if(dp[last][n][k] != -1)
            return dp[last][n][k];
        
        int ways = 0;
        if(last == 0)
            last++;
        for(int i = last; i <= n; i++)
        {
            if(n - i >= 0)
                ways += solve(i, n - i, k - 1);
        }
        
        return dp[last][n][k] = ways;
    }
    
  public:
    int countWaystoDivide(int n, int kk) {
        
        for(int i = 0; i <= n; i++)
            for(int j = 0; j <= n; j++)
                for(int k = 0; k <= kk; k++)
                    dp[i][j][k] = -1;
        
        return solve(0, n, kk);
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        Solution ob;
        cout << ob.countWaystoDivide(N, K) << endl;
    }
}
// } Driver Code Ends