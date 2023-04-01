//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long int minOperations(int n) {
        // Code here
        
        // 3  1  1  3
        // 1  3  5  7
        
        // 4  2  0  2  4
        // 1  3  5  7  9
        
        long long ans = 0;
        
        if(n % 2)
        {
            n /= 2;
            ans = (n * (4 + (n - 1) * 2LL)) / 2;
        }
        else
        {
            n /= 2;
            ans = (n * (2 + (n - 1) * 2LL)) / 2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.minOperations(n) << endl;
    }
    return 0;
}
// } Driver Code Ends