//{ Driver Code Starts
//Initial Template for C++



#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    public:
        // Function to return the length of the
        //longest subarray with ppositive product
        int maxLength(vector<int> &arr,int n){
           //code here
           n++;
           arr.push_back(0);
           int ans = 0, i = 0, j = 0, negs = 0;
           
           while(j < n)
           {
                if(arr[j] == 0)
                {
                    j++;
                    i = j, negs = 0;
                    continue;
                }
                
                if(arr[j] < 0)
                    negs++;
                
                if(negs % 2 == 0)
                    ans = max(ans, j - i + 1);
                
                j++;
           }
           
           arr.pop_back();
           reverse(arr.begin(), arr.end());
           arr.push_back(0);
           
           i = 0, j = 0, negs = 0;
           
           while(j < n)
           {
                if(arr[j] == 0)
                {
                    j++;
                    i = j, negs = 0;
                    continue;
                }
                
                if(arr[j] < 0)
                    negs++;
                
                if(negs % 2 == 0)
                    ans = max(ans, j - i + 1);
                
                j++;
           }
           
           return ans;
        }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    vector<int> arr(n);
	    for(int i = 0;i<n;i++){
	        cin>>arr[i];
	    }
	    Solution ob;
	    int res = ob.maxLength(arr,n);
	    cout<<res<<"\n";
	}
	return 0;
}
// } Driver Code Ends