//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends
class Solution {
    
    bool solve(int idx, int k, int target, vector<int> &coins, vector<vector<vector<int>>> &dp)
    {
        int n = coins.size();
        if(k == 0 && target == 0)
            return true;
        if(k == 0 || target == 0)
            return false;    
        if(idx == n)
            return false;
        if(dp[idx][k][target] != -1)
            return dp[idx][k][target];
        
        bool way1 = false, way2 = false;
        way1 = solve(idx + 1, k, target, coins, dp);
        if(target >= coins[idx])
            way2 = solve(idx, k - 1, target - coins[idx], coins, dp);
        
        return dp[idx][k][target] = (way1 | way2);
    }
    
  public:
    bool makeChanges(int n, int k, int target, vector<int> &coins) {
        
        
        vector<vector<vector<int>>> dp(n, vector<vector<int>> (k + 1, vector<int> (target + 1, -1)));
        return solve(0, k, target, coins, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int N;
        scanf("%d", &N);

        int K;
        scanf("%d", &K);

        int target;
        scanf("%d", &target);

        vector<int> coins(N);
        Array::input(coins, N);

        Solution obj;
        bool res = obj.makeChanges(N, K, target, coins);

        cout << res << endl;
    }
}

// } Driver Code Ends