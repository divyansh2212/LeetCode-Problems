//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
         int n = s.length();
        
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, 0));
        
        int maxLen = 1, start = 0;
        for(int i = 0; i < n; i++)
            dp[i][i] = 1;
        for(int i = 1; i < n; i++)
        {
            if(s[i] == s[i - 1])
            {
                dp[i - 1][i] = 1;
                if(maxLen == 1)
                    start = i - 1, maxLen = 2;
            }
        }
        
        for(int len = 3; len <= n; len++)
        {
            for(int i = 0; i < n; i++)
            {
                int j = i + len - 1;
                if(j >= n)
                    break;
                    
                if(s[i] == s[j] && dp[i + 1][j - 1] == 1)
                {
                    dp[i][j] = 1;
                    if(len > maxLen)
                        maxLen = len, start = i;
                }
            }
        }
        
        return s.substr(start, maxLen);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends