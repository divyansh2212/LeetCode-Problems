//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int isPerfectNumber(long long n) {
        if(n==1)return 0;
        long long ans = 0;
        for(long long i = 1; i*i <= n; i++)
        {
            if(n % i == 0) 
            {
                ans += i;
                if(n / i != i && n / i != n) {
                    ans += (n / i);
                }
            }
        }
        
        return (ans == n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        
        cin>>N;

        Solution ob;
        cout << ob.isPerfectNumber(N) << endl;
    }
    return 0;
}
// } Driver Code Ends