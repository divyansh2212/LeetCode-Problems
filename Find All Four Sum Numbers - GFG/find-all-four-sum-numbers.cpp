//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:

    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        int n = arr.size();
        
        for(int i = 0; i < n - 3; i++) {
            if(i > 0 && arr[i] == arr[i - 1])
                continue;
            for(int j = i + 1; j < n - 2; j++) {
                if(j > i + 1 && arr[j] == arr[j - 1])
                    continue;
                int start = j + 1, end = n - 1;
                
                while(start < end) {
                    int curr = arr[i] + arr[j] + arr[start] + arr[end];
                    if(curr == k) {
                        ans.push_back({arr[i], arr[j], arr[start], arr[end]});
                        while (start < end && arr[start] == arr[start + 1])
                        start++;
                    while (start < end && arr[end] == arr[end - 1])
                        end--;
                    start++;
                    end--;
                    }
                    else if(curr > k) {
                        end--;
                    }
                    else
                        start++;
                }
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
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends