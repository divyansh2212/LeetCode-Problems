//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    
    bool solve(int idx, string &s, unordered_set<string> &st, vector<int> &dp)
    {
        int n = s.length();
        if(idx == n) {
            return true;
        }
        
        if(dp[idx] != -1)
            return dp[idx];
        
        string curr = "";
        bool flag = false;
        for(int i = idx; i < n; i++) {
            curr.push_back(s[i]);
            if(st.find(curr) != st.end()) {
                flag |= solve(i + 1, s, st, dp);
            }
        }
        
        return dp[idx]=flag;
    }
    
    
public:
    int wordBreak(string str, vector<string> &words) {
        //code here
        unordered_set<string> st(words.begin(), words.end());
        int n = str.length();
        vector<int> dp(n, -1);
        return solve(0, str, st, dp);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends