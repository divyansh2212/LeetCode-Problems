//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    long long ways(int coins[], int n, int target, int idx)
    {
        if(target == 0)
            return 1;
        if(idx == n)
            return 0;
        
        long long way1 = ways(coins, n, target, idx + 1);
        long long way2 = 0;
        
        if(target >= coins[idx])
            way2 = ways(coins, n, target - coins[idx], idx);
        
        return way1 + way2;
    }
    
  public:
    long long int count(int coins[], int n, int sum) {

        // return ways(coins, n, sum, 0);
        
        vector<vector<long long>> dp(n + 1, vector<long long> (sum + 1, 0));
        
        for(int i = 0; i < n; i++)
            dp[i][0] = 1;
            
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int target = 1; target <= sum; target++)
            {
                long long way1 = dp[idx + 1][target];
                long long way2 = 0;
        
                if(target >= coins[idx])
                    way2 = dp[idx][target - coins[idx]];
        
                dp[idx][target] = way1 + way2;
            }
        }
        
        return dp[0][sum];
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int sum, N;
        cin >> sum >> N;
        int coins[N];
        for (int i = 0; i < N; i++) cin >> coins[i];
        Solution ob;
        cout << ob.count(coins, N, sum) << endl;
    }

    return 0;
}


// } Driver Code Ends