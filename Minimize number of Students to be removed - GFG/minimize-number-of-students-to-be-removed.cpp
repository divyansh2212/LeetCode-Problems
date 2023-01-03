//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int removeStudents(int h[], int n) {
        // code her
        vector<int> ans;
        
        for(int i = 0; i < n; i++)
        {
            auto it = lower_bound(ans.begin(), ans.end(), h[i]) - ans.begin();
            
            if(it == ans.size())
                ans.push_back(h[i]);
            else
                ans[it] = h[i];
        }
        
        return n - ans.size();
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin>>N;
        
        int H[N];
        for(int i=0; i<N; i++)
            cin>>H[i];

        Solution ob;
        cout << ob.removeStudents(H,N) << endl;
    }
    return 0;
}
// } Driver Code Ends