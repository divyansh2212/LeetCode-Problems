//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution{
    
    bool solve(vector<int>& arr, long long mid, int &k)
    {
        int n = arr.size();
        int counts = 0;
        long long currSum = 0;
        
        for(int i = 0; i < n; i++){
            currSum += arr[i];
            if(currSum >= mid){
                currSum = 0;
                counts++;
            }
        }
        
        return (counts >= k + 1);
    }
    
    public:
    int maxSweetness(vector<int>& arr, int n, int k) {
    // Write your code here.
        long long lo = 0, hi = 1e15, ans = 0;
        
        while(lo <= hi)
        {
            long long mid = lo + (hi - lo) / 2;
            if(solve(arr, mid, k)) {
                ans = mid;
                lo = mid + 1;
            }
            else{
                hi = mid - 1;
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
        int n, k;
        cin >> n >> k;
        vector<int> sweetness(n);
        for (int i = 0; i < n; i++) {
            cin >> sweetness[i];
        }
          Solution ob;
          int res=ob.maxSweetness(sweetness, n, k);
        cout << res << endl;
    }
}
// } Driver Code Ends