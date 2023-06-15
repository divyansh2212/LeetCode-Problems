//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    bool is_palindrome(string s)
    {
        int i = 0, j = s.length() - 1;
        while(i <= j)
        {
            if(s[i] != s[j])
                return false;
            i++, j--;
        }
        
        return true;
    }
    
  public:
    string longestPalin (string s) {
        // code here
        
        int n = s.length();
        string ans = "";
        
        for(int i = 0; i < n; i++)
        {
            for(int j = i; j < n; j++)
            {
                int len = j - i + 1;
                if(len > ans.length() && is_palindrome(s.substr(i, len)))
                    ans = s.substr(i, len);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends