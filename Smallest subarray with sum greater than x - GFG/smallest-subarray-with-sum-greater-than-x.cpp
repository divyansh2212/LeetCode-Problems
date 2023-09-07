//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:

    int smallestSubWithSum(int arr[], int n, int x)
    {
        // Your code goes here 
        int ans = 1e9;
        
        int i = 0, j = 0;
        int sum = 0;
        
        while(j < n) {
            sum += arr[j];
            
            while(sum > x && i <= j) {
                ans = min(ans, j - i + 1);
                sum -= arr[i];
                i++;
            }
            j++;
        }
        if(ans == 1e9)
            return 0;
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	// your code goes here
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution obj;
		cout<<obj.smallestSubWithSum(a,n,x)<<endl;
	}
	return 0;
}
// } Driver Code Ends