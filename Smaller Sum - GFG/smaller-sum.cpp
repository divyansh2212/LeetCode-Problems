//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
public:
    vector<long long> smallerSum(int n,vector<int> &arr){
        // Code here
        map<int, long long> mp;
        
        for(int i = 0; i < n; i++)
            mp[arr[i]]++;
        
        long long prev = 0;
        for(auto &it : mp)
        {
            int freq = it.second;
            it.second = prev;
            prev = prev + (freq * it.first);
        }
        
        vector<long long> ans(n, 0);
        for(int i = 0; i < n; i++){
            ans[i] = mp[arr[i]];
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
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob; 
        vector<long long> ans=ob.smallerSum(n,arr);
        for(int i=0;i<n;i++){
            if(i!=n-1){
                cout<<ans[i]<<" ";
            }
            else{
                cout<<ans[i]<<endl;
            }
        }
    }
    return 0;
}
// } Driver Code Ends