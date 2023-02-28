//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    vector<int> optimalArray(int n,vector<int> &a){
        // Code here
        vector<int> ans(n, 0);
        vector<int> prefix(n, 0);
        prefix[0] = a[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + a[i];
        
        int sum = a[0];
        for(int i = 1; i < n; i++)
        {
            sum += a[i];
            int idx = i / 2;
            
            ans[i] = abs(((i - idx) * a[idx]) - (prefix[i] - prefix[idx]));
            if(idx - 1 >= 0)
                ans[i] += abs(prefix[idx - 1] - (idx  * a[idx]));
            
        }
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
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        Solution obj;
        vector<int> ans=obj.optimalArray(n,a);
        for(auto ele:ans){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends