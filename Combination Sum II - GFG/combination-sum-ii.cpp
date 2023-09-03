//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
    void solve(vector<int> &arr, int target, vector<vector<int>> &ans, vector<int> &curr, int idx)
    {
        int n = arr.size();
        if(target == 0) {
            ans.push_back(curr);
            return;
        }
        if(idx == n)
            return;
        
        for(int i = idx; i < n; i++) {
            if(arr[i] > target)
                break;
            if(i > idx && arr[i] == arr[i - 1])
                continue;
            curr.push_back(arr[i]);
            solve(arr, target - arr[i], ans, curr, i + 1);
            curr.pop_back();
        }
        
    }
    
  public:
    vector<vector<int>> combinationSum2(vector<int> &arr, int target) {
        sort(arr.begin(), arr.end());
        vector<vector<int>> ans;
        vector<int> curr;
        solve(arr, target, ans, curr, 0);
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> candidates(n);
        for (int i = 0; i < n; ++i) {
            cin >> candidates[i];
        }
        // char marker;
        // cin >> marker;

        Solution obj;

        vector<vector<int>> comb = obj.combinationSum2(candidates, k);
        sort(comb.begin(), comb.end());
        cout << "[ ";
        for (int i = 0; i < comb.size(); i++) {
            cout << "[ ";
            for (int j = 0; j < comb[i].size(); j++) {
                cout << comb[i][j] << " ";
            }
            cout << "]";
        }
        cout << " ]\n";

        // cout << "\n~\n";
    }
    fclose(stdout);
    return 0;
}

// } Driver Code Ends