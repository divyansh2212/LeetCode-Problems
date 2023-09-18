//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    
    string solve(string &s, int idx) {
        if(idx == s.length())
            return "";
        if(idx == 0 || (idx > 0 && s[idx] != s[idx - 1])) {
            return s[idx] + solve(s, idx + 1);
        }
        return solve(s, idx + 1);
    }
    
    public:
    string removeConsecutiveCharacter(string s)
    {
        return solve(s, 0);
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends