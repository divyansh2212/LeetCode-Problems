//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int solve(int idx, int &n, int w, int val[], int wt[], vector<vector<int>> &dp)
    {
        if(idx == n || wt == 0) {
            return 0;
        }
        if(dp[idx][w] != -1) {
            return dp[idx][w];
        }
        
        int way1 = solve(idx + 1, n, w, val, wt, dp);
        int way2 = 0;
        if(w >= wt[idx]) {
            way2 = val[idx] + solve(idx, n, w - wt[idx], val, wt, dp);
        }
        
        return dp[idx][w] = max(way1, way2);
    }
    
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
        vector<vector<int>> dp(n, vector<int> (w + 1, -1));
        return solve(0, n, w, val, wt, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}
// } Driver Code Ends