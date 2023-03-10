//{ Driver Code Starts
//Initial Template for CPP

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    long long maxTripletProduct(long long arr[], int n)
    {
    	// Complete the function
    	long long ans = -2e18;
    	// 3 POS
    	sort(arr, arr + n);
    	ans = max(ans, arr[n - 1] * arr[n - 3] * arr[n - 2]);
    	
    	// 2 NEG, 1 POS
    	ans = max(ans, arr[0] * arr[1] * arr[n - 1]);
    	
    	// 3 NEG
    	ans = max(ans, arr[0] * arr[1] * arr[2]);
    	
    	// 1 NEG, 2POS
    	ans = max(ans, arr[0] * arr[n - 2] * arr[n - 1]);
    	
    	return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i;
	    cin>>n; long long arr[n];
	    for(i=0;i<n;i++)
	    cin>>arr[i];
	    Solution ob;
	    cout <<ob.maxTripletProduct(arr, n);
	    cout<<"\n";
	}
    return 0;
}
// } Driver Code Ends