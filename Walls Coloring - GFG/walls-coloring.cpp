//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{   
    
    int costcalc(int idx, vector<vector<int>> &colors, int last, vector<vector<int>> &dp)
    {
        int n = colors.size();
        
        if(idx == n - 1)
        {
            if(last == 0)
                return min(colors[idx][1], colors[idx][2]);
            else if(last == 1)
                return min(colors[idx][0], colors[idx][2]);
            else if(last == 2)
                return min(colors[idx][0], colors[idx][1]);
            else
                return min({colors[idx][0], colors[idx][1], colors[idx][2]});
        }
        
        if(dp[idx][last] != -1)
            return dp[idx][last];
        
        int way1 = INT_MAX, way2 = INT_MAX, way0 = INT_MAX;
            
        if(last == 3)
        {
            way0 = colors[idx][0] + costcalc(idx + 1, colors, 0, dp);
            way1 = colors[idx][1] + costcalc(idx + 1, colors, 1, dp);
            way2 = colors[idx][2] + costcalc(idx + 1, colors, 2, dp);
        }
        
        else if(last == 0)
        {
            way1 = colors[idx][1] + costcalc(idx + 1, colors, 1, dp);
            way2 = colors[idx][2] + costcalc(idx + 1, colors, 2, dp);
        }
        
        else if(last == 1)
        {
            way0 = colors[idx][0] + costcalc(idx + 1, colors, 0, dp);
            // way1 = colors[idx][1] + costcalc(idx + 1, colors, 1);
            way2 = colors[idx][2] + costcalc(idx + 1, colors, 2, dp);
        }
            
        else
        {
            way0 = colors[idx][0] + costcalc(idx + 1, colors, 0, dp);
            way1 = colors[idx][1] + costcalc(idx + 1, colors, 1, dp);
            // way2 = colors[idx][2] + costcalc(idx + 1, colors, 2);
        }
        
        return dp[idx][last] = min({way0, way1, way2});
    }
    
public:
    int minCost(vector<vector<int>> &colors, int n) {
        
        vector<vector<int>> dp(n, vector<int> (4, -1));
        return costcalc(0, colors, 3, dp);
        // Write your code here.
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        int n;
        cin >> n;
        vector<vector<int>> colors(n, vector<int>(3));
        for (int i = 0; i < n; i++)
            cin >> colors[i][0] >> colors[i][1] >> colors[i][2];
            
        Solution ob;
        cout << ob.minCost(colors, n) << endl;    
    }
}
// } Driver Code Ends