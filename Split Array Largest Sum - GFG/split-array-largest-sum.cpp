//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    int minmSum = -1;
    bool check(int arr[], int &k, int &n, int mid)
    {
        int count = 1;
        int currSum = 0;
        for(int i = 0; i < n; i++)
        {
            if(arr[i] > mid)
                return false;
            if(currSum + arr[i] <= mid)
                currSum += arr[i];
            else
                currSum = arr[i], count++;
        }
        if(k >= count)
        {
            // int currSum = 0;
            // int currMin = -1;
            // for(int i = 0; i < n; i++)
            // {
            //     if(currSum + arr[i] <= mid)
            //         currSum += arr[i];
            //     else
            //         currSum = arr[i];
            //     currMin = max(currMin, currSum);
            // }
            // minmSum = min(minmSum, currMin);
            return true;
        }
        return false;
    }
    
  public:
    int splitArray(int arr[] ,int n, int k) {
        
        int sum = 0;
        for(int i = 0; i < n; i++) sum += arr[i];
        minmSum = sum;
        
        int lo = 1, hi = sum , mid, ans = sum;
        
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if(check(arr, k, n, mid))
                hi = mid - 1, ans = mid;
            else
                lo = mid + 1;
        }
        
        return ans;
        // return minmSum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        
        cin>>N>>K;
        int arr[N];
        
        for(int i=0 ; i<N ; i++)
            cin>>arr[i];

        Solution ob;
        cout<<ob.splitArray(arr,N,K);
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends