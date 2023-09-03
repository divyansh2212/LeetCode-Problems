//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
    
    bool isPalindrome(string &s)
    {
        int i = 0, j = s.length() - 1;
        while(i < j) {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        return true;
    }
    
    void solve(vector<vector<string>> &ans, vector<string> &curr, string &s, int idx)
    {
        int n = s.length();
        if(idx == n) {
            ans.push_back(curr);
            return;
        }
        
        string temp = "";
        for(int i = idx; i < n; i++) {
            temp.push_back(s[i]);
            if(isPalindrome(temp)) {
                curr.push_back(temp);
                solve(ans, curr, s, i + 1);
                curr.pop_back();    
            }
        }
        
    }
    
  public:
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>> ans;
        vector<string> curr;
        
        solve(ans, curr, s, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends