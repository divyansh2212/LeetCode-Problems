//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution {
    
  public:
    long long maxPossibleValue(int n, vector<int> lengths, vector<int> units) {
        // code here
        long long ans = 0;
        long long freq = 0;
        long long lowest = INT_MAX;
        int lowIdx = -1;
        
        for(int i = 0; i < n; i++)
        {
            if(units[i] > 1)
            {
                freq += units[i];
                if(units[i] % 2)
                    freq--, units[i]--;
                ans += (units[i] * 1LL * lengths[i]);
                if(lengths[i] < lowest)
                    lowest = lengths[i], lowIdx = i;
            }
        }
        
        if(freq % 4)
            ans -= (2* lowest);
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        vector<int> A(N), B(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        for(int i=0;i<N;i++){
          cin>>B[i];
        }
        Solution obj;
        auto ans = obj.maxPossibleValue(N,A,B);
        cout<<ans<<endl;
    }
} 
// } Driver Code Ends