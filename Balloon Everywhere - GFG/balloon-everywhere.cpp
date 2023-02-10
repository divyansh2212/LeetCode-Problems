//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int maxInstance(string s){
        int ans = 1e9, n = s.length();
        
        vector<int> hsh(26, 0);
        
        for(int i = 0; i < n; i++)
            hsh[s[i] - 'a']++;
        
        ans = min(ans, hsh[1]);
        ans = min(ans, hsh[0]);
        ans = min(ans, hsh[11] / 2);
        ans = min(ans, hsh[14] / 2);
        ans = min(ans, hsh[13]);
        
        
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.maxInstance(s)<<endl;
    }
    return 0;
}
// } Driver Code Ends