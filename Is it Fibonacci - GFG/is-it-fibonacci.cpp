//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    long long solve(int n, int k, vector<long long> geeknum) {
        // code here
        if(n <= k)
            return geeknum[n - 1];
        
        long long total = 0;
        
        for(int i = 0; i < k; i++)
            total += geeknum[i];
            
        geeknum.push_back(total);
        
        for(int i = k; i < n; i++)
        {
            total -= geeknum[i - k];
            total += geeknum[i];
            geeknum.push_back(total);
        }
        
        return geeknum[geeknum.size() - 2];
    }
};


//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, K;
        cin >> N >> K;

        vector<long long> GeekNum(K);

        for (int i = 0; i < K; i++) cin >> GeekNum[i];

        Solution ob;
        cout << ob.solve(N, K, GeekNum) << "\n";
    }
    return 0;
}

// } Driver Code Ends