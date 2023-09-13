//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string findLargest(int n, int s){
        // code here
        if(s == 0) {
            if(n == 1) return "0";
            return "-1";
        }
        string ans = "";
        while (n--) {
            int digit = min(s, 9);
            s -= digit;
            ans.push_back('0' + digit);
        }
        
        if(s > 0)
            return "-1";
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, S;
        cin>>N>>S;
        
        Solution ob;
        cout<<ob.findLargest(N, S)<<"\n";
    }
    return 0;
}
// } Driver Code Ends