//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
    
    int profit(int idx, int last, vector<vector<int>> &intervals, vector<vector<int>> &dp)
    {
        if(idx == intervals.size())
            return 0;
            
        if(dp[idx][last + 1] != -1)
            return dp[idx][last + 1];
            
        int pick = 0, notPick = 0;
        notPick = profit(idx + 1, last, intervals, dp);
        if(last == -1 || (intervals[last][1] <= intervals[idx][0] && intervals[last][0] < intervals[idx][0]))
            pick = intervals[idx][2] + profit(idx + 1, idx, intervals, dp);
            
        return dp[idx][last + 1] = max(pick, notPick);
    }
    
    
  public:
    int maximum_profit(int n, vector<vector<int>> &intervals) {
        
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int last = -1; last < idx; last++)
            {
                int pick = 0, notPick = 0;
                notPick = dp[idx + 1][last + 1];
                if(last == -1 || (intervals[last][1] <= intervals[idx][0] && intervals[last][0] < intervals[idx][0]))
                    pick = intervals[idx][2] + dp[idx + 1][idx + 1];
            
                dp[idx][last + 1] = max(pick, notPick);
            }
        }
        
        return dp[0][0];
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> intervals(n, vector<int>(3));
        for (int i = 0; i < n; i++) {
            cin >> intervals[i][0] >> intervals[i][1] >> intervals[i][2];
        }
        Solution obj;
        cout << obj.maximum_profit(n, intervals) << endl;
    }
    return 0;
}

// } Driver Code Ends