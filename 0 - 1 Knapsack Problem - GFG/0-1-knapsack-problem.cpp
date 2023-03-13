//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    int maxProfit(int w, int wt[], int val[], int &n, int idx)
    {
        if(idx == n)
            return 0;
        int way1 = maxProfit(w, wt, val, n, idx + 1);
        int way2 = 0;
        if(w >= wt[idx])
            way2 = val[idx] + maxProfit(w - wt[idx], wt, val, n, idx + 1);
            
        return max(way1, way2);
    }
    
    public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int totWt, int wt[], int val[], int n) 
    { 
        // return maxProfit(totWt, wt, val, n, 0);
        vector<vector<int>> dp(n + 1, vector<int> (totWt + 1, 0));
       
        for(int idx = n - 1; idx >= 0; idx--)
        {
            for(int w = 0; w <= totWt; w++)
            {
                int way1 = dp[idx + 1][w];
                int way2 = 0;
                if(w >= wt[idx])
                    way2 = val[idx] + dp[idx + 1][w - wt[idx]];
            
                dp[idx][w] = max(way1, way2);
            }
        }
       
       return dp[0][totWt];
    }
};

//{ Driver Code Starts.

int main()
 {
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //reading number of elements and weight
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        Solution ob;
        //calling method knapSack()
        cout<<ob.knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends