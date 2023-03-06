//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {

  public:
    int noConseBits(int n) {
        // code here
        int ans = n;
        for(int i = 30; i >= 2;)
        {
        if((n & (1 << i)) && (n & (1 << (i - 1))) && (n & (1 << (i - 2))) )
            ans -= (1 << (i - 2)), i -= 3;
            else i--;
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int tt;
    cin >> tt;
    Solution sol;
    while (tt--) {

        int n;
        cin >> n;
        int ans = sol.noConseBits(n);
        cout << ans << '\n';
    }

    return 0;
}

// } Driver Code Ends