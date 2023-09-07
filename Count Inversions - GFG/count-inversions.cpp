//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


#define ll long long
class Solution {
    
    void merge(ll start, ll end, long long arr[], long long &ans)
    {
        if (start >= end)
            return;
        ll mid = start + (end - start) / 2;
        int len1 = mid - start + 1;
        int len2 = end - mid;
        
        vector<ll> first(len1, 0);
        vector<ll> second(len2, 0);
        
        int idx = start;
        for (int i = 0; i < len1; i++) {
            first[i] = arr[idx++];
        }
        for (int i = 0; i < len2; i++) {
            second[i] = arr[idx++];
        }
        
        int i = 0, j = 0;
        idx = start;
        
        while (i < len1 && j < len2) {
            if (first[i] <= second[j]) {
                arr[idx++] = first[i++];
            }
            else {
                arr[idx++] = second[j++];
                ans += len1 - i; // Update the inversion count
            }
        }
        
        while (i < len1) {
            arr[idx++] = first[i++];
        }
        
        while (j < len2) {
            arr[idx++] = second[j++];
        }
        
    }
    
    void mergeSort(ll start, ll end, long long arr[], long long &ans)
    {
        if (start >= end)
            return;
        ll mid = start + (end - start) / 2;
        mergeSort(start, mid, arr, ans);
        mergeSort(mid + 1, end, arr, ans);
        merge(start, end, arr, ans);
    }
    
public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long n)
    {
        // Your Code Here
        long long ans = 0;
        mergeSort(0, n - 1, arr, ans);
        
        return ans;
    }

};


//{ Driver Code Starts.

int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        Solution obj;
        cout << obj.inversionCount(A,N) << endl;
    }
    
    return 0;
}

// } Driver Code Ends