//{ Driver Code Starts
// C++ program to find minimum swaps required
// to club all elements less than or equals
// to k together
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends

class Solution
{
public:
    int minSwap(int arr[], int n, int k) {

        int count = 0;
        for(int i = 0; i < n; i++) {
            if(arr[i] <= k) count++;
        }
        if(count == 0)
            return 0;
        int i = 0, j = 0;
        int curr = 0;
        int ans = 1e9;
        
        while(j < n) {
            if(arr[j] > k)
                curr++;
            if(j - i + 1 == count) {
                ans = min(ans, curr);
                if(arr[i] > k) {
                    curr--;
                }
                i++;
            }
            j++;
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

// Driver code
int main() {

	int t,n,k;
	cin>>t;
	while(t--)
    {
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        cin>>k;
        Solution ob;
        cout << ob.minSwap(arr, n, k) << "\n";
    }
	return 0;
}

// } Driver Code Ends