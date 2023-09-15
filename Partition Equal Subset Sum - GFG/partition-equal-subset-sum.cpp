//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool solve(int &n, int arr[], int idx, int target, vector<vector<int>> &dp)
    {
        if(target == 0)
            return true;
        if(idx == n)
            return false;
        
        if(dp[idx][target] != -1)
            return dp[idx][target];
            
        bool way1 = solve(n, arr, idx + 1, target, dp);
        bool way2 = false;
        if(target >= arr[idx]) {
            way2 = solve(n, arr, idx + 1, target - arr[idx], dp);
        }
        
        return dp[idx][target]=(way1 | way2);
    }
    
public:
    int equalPartition(int n, int arr[])
    {
        // code heren
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
        }
        
        if(sum % 2)
            return 0;
        
        vector<vector<int>> dp(n, vector<int> (sum / 2 + 1, -1));
        return solve(n, arr, 0, sum / 2, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends