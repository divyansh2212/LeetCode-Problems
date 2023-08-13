//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    const int mod = 1e9 + 7;
  public:
    int nthFibonacci(int n){
        if(n <= 2)
            return 1;
        int a = 1, b = 1;
        
        for(int i = 3; i <= n; i++) {
            int curr = (a + 0LL+b) % mod;
            a = b;
            b = curr;
        }
        return b;
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
        cout << ob.nthFibonacci(n) << endl;
    }
    return 0;
}

// } Driver Code Ends