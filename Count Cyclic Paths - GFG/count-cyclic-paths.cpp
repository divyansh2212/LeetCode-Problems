//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
    const int mod = 1e9 + 7;
    
    int count(int n, int last, vector<vector<int>> &dp)
    {
        if(n == 0)
        {
            if(last == 0)
                return 1;
            else
                return 0;
        }
        
        if(dp[n][last] != -1)
            return dp[n][last];
        
        int way1 = 0, way2 = 0, way3 = 0;
        if(last == 0)
        {
            way1 = count(n - 1, 1, dp);
            way2 = count(n - 1, 2, dp);
            way3 = count(n - 1, 3, dp);
        }
        
        else if(last == 1)
        {
            way1 = count(n - 1, 1, dp);
            way2 = count(n - 1, 0, dp);
            way3 = count(n - 1, 2, dp);
        }
        
        else if(last == 2)
        {
            way1 = count(n - 1, 0, dp);
            way2 = count(n - 1, 1, dp);
            way3 = count(n - 1, 3, dp);
        }
        
        else
        {
            way1 = count(n - 1, 0, dp);
            way2 = count(n - 1, 1, dp);
            way3 = count(n - 1, 2, dp);
        }
        
        
        return dp[n][last] = (way1 + 0LL + way2 + way3) % mod;
    }
    
public:
    int countPaths(int nn){
        // code here 
        
        vector<vector<int>> dp(nn + 1, vector<int> (4, 0));
        
        dp[0][0] = 1;
        
        for(int n = 1; n <= nn; n++)
        {
            for(int last = 0; last <= 3; last++)
            {
                int way1 = 0, way2 = 0, way3 = 0;
                if(last == 0)
                {
                    way1 = dp[n - 1][1];
                    way2 = dp[n - 1][2];
                    way3 = dp[n - 1][3];
                }
                
                else if(last == 1)
                {
                    way1 = dp[n - 1][1];
                    way2 = dp[n - 1][0];
                    way3 = dp[n - 1][3];
                }
                
                else if(last == 2)
                {
                    way1 = dp[n - 1][1];
                    way2 = dp[n - 1][0];
                    way3 = dp[n - 1][3];
                }
                
                else
                {
                    way1 = dp[n - 1][1];
                    way2 = dp[n - 1][2];
                    way3 = dp[n - 1][0];
                }
                dp[n][last] = (way1 + 0LL + way2 + way3) % mod;
            }
        }
        
        return dp[nn][0];
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        cout << ob.countPaths(N) << endl;
    }
    return 0; 
}

// } Driver Code Ends