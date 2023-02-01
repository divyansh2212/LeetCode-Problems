//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
    
    // 1 ---> r
    // 2 ---> g
    // 3 ---> b
    
    long long int cost(int n, int r[], int g[], int b[], int idx, int last, vector<vector<long long int>> &dp)
    {
        if(idx == n)
            return 0;
            
        if(dp[idx][last] != -1)
            return dp[idx][last];
            
        long long int way1 = 1e11, way2 = 1e11, way3 = 1e11;    
        
        if(last == 0)
        {
            way1 = r[idx] + cost(n, r, g, b, idx + 1, 1, dp);
            way2 = g[idx] + cost(n, r, g, b, idx + 1, 2, dp);
            way3 = b[idx] + cost(n, r, g, b, idx + 1, 3, dp);
        }
        
        else if(last == 1)
        {
            way2 = g[idx] + cost(n, r, g, b, idx + 1, 2, dp);
            way3 = b[idx] + cost(n, r, g, b, idx + 1, 3, dp);
        }
        
        else if(last == 2)
        {
            way1 = r[idx] + cost(n, r, g, b, idx + 1, 1, dp);
            way3 = b[idx] + cost(n, r, g, b, idx + 1, 3, dp);
        }
        
        else
        {
            way1 = r[idx] + cost(n, r, g, b, idx + 1, 1, dp);
            way2 = g[idx] + cost(n, r, g, b, idx + 1, 2, dp);
        }
        
        return dp[idx][last] = min(way1, min(way2, way3));
    }
    
public:
    long long int distinctColoring(int n, int r[], int g[], int b[]){
        // code here 
        
        vector<vector<long long int>> dp(n, vector<long long int> (4, -1));
        
        return cost(n, r, g, b, 0, 0, dp);
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
        int r[N],g[N],b[N];
        for(int i = 0; i < N; i++)
            cin >> r[i];
        for(int i = 0; i < N; i++)
            cin >> g[i];
        for(int i = 0; i < N; i++)
            cin >> b[i];
        
        Solution ob;
        cout << ob.distinctColoring(N, r, g, b) << endl;
    }
    return 0; 
}
// } Driver Code Ends