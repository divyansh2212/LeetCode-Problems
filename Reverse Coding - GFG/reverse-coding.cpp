//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    const int mod = 1e9 + 7;
    
    int binExp(int a, int b)
    {
        int result = 1;
        while(b)
        {
            if(b & 1)
                result = (result * 1LL * a) % mod;
            a = (a * 1LL * a) % mod;
            b = (b >> 1);
        }
        
        return result;
    }
    
  public:
    int sumOfNaturals(int n) {
        // code here
        
        int ans = (n * 1LL * (n + 1)) % mod;
        
        ans = (ans * 1LL* binExp(2, mod - 2)) % mod;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        cout << ob.sumOfNaturals(n) << endl;
    }
    return 0;
}
// } Driver Code Ends