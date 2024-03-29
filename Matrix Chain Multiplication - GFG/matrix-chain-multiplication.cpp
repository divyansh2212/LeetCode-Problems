//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    
    int solve(int &n, int arr[], int i, int j, vector<vector<int>> &dp)
    {
        if(i == j)
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        int steps = 1e9;
        
        for(int k = i; k <= j - 1; k++)
        {
            steps = min(steps, arr[i - 1] * arr[k] * arr[j] + solve(n, arr, i, k, dp) + solve(n, arr, k + 1, j, dp));
        }
        return dp[i][j] = steps;            
    }
    
public:
    int matrixMultiplication(int n, int arr[])
    {
        // code here
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return solve(n, arr, 1, n - 1, dp);
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
        cout<<ob.matrixMultiplication(N, arr)<<endl;
    }
    return 0;
}
// } Driver Code Ends