//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int minOperation(string s) {
        // code here
        int n = s.length(), ans = n;
        
        string curr = "";
        
        for(int i = 0; i < n; i++)
        {
            curr.push_back(s[i]);
            
            string newcurr = "";
            for(int j = i + 1; j < min(n, 2*i + 2); j++)
                newcurr.push_back(s[j]);
                
            if(curr == newcurr)
                ans = min(ans, n - i);
            
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.minOperation(s) << "\n";
    }
    return 0;
}

// } Driver Code Ends