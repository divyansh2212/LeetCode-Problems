//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  long long int wineSelling(vector<int>& arr, int n)
  {
      // Code here.
    vector<long long> prefix(n, 0);
    prefix[0] = arr[0];
      
    for(int i = 1; i < n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
        
    long long ans = 0;
    
    for(int i = 0; i < n; i++)
        ans += abs(prefix[i]);
    
    return ans;
  }
};



//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        long long int ans = ob.wineSelling(arr,n);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends