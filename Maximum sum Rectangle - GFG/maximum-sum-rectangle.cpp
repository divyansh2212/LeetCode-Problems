//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
    
    int kadane(vector<int> &arr) {
        int mini = INT_MIN;
        for(int i = 0; i < arr.size(); i++) {
            mini = max(mini, arr[i]);
        }
        if(mini <= 0)
            return mini;
            
        int i = 0;
        int sum = 0;
        int ans = arr[0];
        while(i < arr.size()) {
            sum += arr[i];
            ans = max(ans, sum);
            if(sum < 0)
                sum = 0;
            i++;
        }
        
        return ans;
    }
    
  public:
    int maximumSumRectangle(int n, int m, vector<vector<int>> mat) {
        // code here
        int ans = INT_MIN;
        for(int c1 = 0; c1 < m; c1++) {
            
            vector<int> arr(n, 0);
            for(int c2 = c1; c2 < m; c2++) {
                for(int i = 0; i < n; i++) {
                    arr[i] += mat[i][c2];
                }
                ans = max(ans, kadane(arr));
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}
// } Driver Code Ends