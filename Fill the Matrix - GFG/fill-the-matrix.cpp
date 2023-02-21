//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function Template for C++

class Solution{   
    
    vector<int> dx = {-1, 0, 1, 0};
    vector<int> dy = {0, 1, 0, -1};
    
public:
    int minIteration(int n, int m, int x, int y){    
        // code here
        // x--, y--;
        
        
        int ans = 0;
        
        ans = max(ans, y - 1 + x - 1);
        ans = max(ans, y - 1 + n - x);
        ans = max(ans, m - y + x - 1);
        ans = max(ans, m - y + n - x);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N, M, x, y;
        cin >> N >> M;
        cin >> x >> y;
        
        Solution ob;
        cout << ob.minIteration(N, M, x, y) << endl;
    }
    return 0; 
} 
// } Driver Code Ends