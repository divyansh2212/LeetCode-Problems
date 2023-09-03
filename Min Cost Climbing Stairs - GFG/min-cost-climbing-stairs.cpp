//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Back-end complete function Template for C++

class Solution {
    
    int solve(int idx, vector<int> &cost, vector<int> &dp)
    {
        int n = cost.size();
        if(idx == n)
            return 0;
        if(dp[idx] != -1)
            return dp[idx];
        int way1 = cost[idx] + solve(idx + 1, cost, dp);
        int way2 = 1e9;
        if(idx + 2 <= n)
            way2 = cost[idx] + solve(idx + 2, cost, dp);
            
        return dp[idx] = min(way1, way2);
    }
    
  public:
    int minCostClimbingStairs(vector<int> &cost, int n) {
        
        vector<int> dp(n, -1);
        return min(solve(0, cost, dp), solve(1, cost, dp));
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;
        vector<int>cost(N);
        
        for(int i=0 ; i<N ; i++){
            cin>>cost[i];
        }

        Solution ob;
        cout<<ob.minCostClimbingStairs(cost,N);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends