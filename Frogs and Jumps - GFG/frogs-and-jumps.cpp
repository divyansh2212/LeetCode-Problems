//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int unvisitedLeaves(int n, int leaves, int frogs[]) {
        // Code here
        
        sort(frogs, frogs + n);
        vector<bool> visitedLeaves(leaves + 1, false);
        
        int curr = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(i > 0 && frogs[i] == frogs[i - 1])
                continue;
            if(frogs[i] == 1 || curr == leaves) return 0;
            for(int j = frogs[i]; j <= leaves; j += frogs[i])
            {
                if(visitedLeaves[j] == false)
                    visitedLeaves[j] = true, curr++;
            }
        }
        
        int ans = 0;
        for(int i = 1; i <= leaves; i++)
            if(visitedLeaves[i] == false)
                ans++;
        
                
        return ans;
    }
};


//{ Driver Code Starts.


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, leaves;
        cin >> N >> leaves;
        int frogs[N];
        for (int i = 0; i < N; i++) {
            cin >> frogs[i];
        }

        Solution ob;
        cout << ob.unvisitedLeaves(N, leaves, frogs) << endl;
    }
}
// } Driver Code Ends