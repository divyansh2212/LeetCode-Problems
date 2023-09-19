//{ Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


// } Driver Code Ends
class Solution
{
    int lcs(string &a, string &b, int idx1, int idx2, vector<vector<int>> &dp)
    {
        int n = a.length(), m = b.length();
        if(idx1 == n || idx2 == m)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(a[idx1] == b[idx2])
            return dp[idx1][idx2] = 1 + lcs(a, b, idx1 + 1, idx2 + 1, dp);
        int way1 = lcs(a, b, idx1+ 1, idx2, dp);
        int way2 = lcs(a, b, idx1, idx2 + 1, dp);
        
        return dp[idx1][idx2] = max(way1, way2);
    }
    
    public:
    int transform (string a, string b)
    {
        //code here.
        if(a == b)
            return 0;
        int n = a.length(), m = b.length();
        if(n != m)
            return -1;
            
        unordered_map<char, int> hsh1;
        unordered_map<char, int> hsh2;
        for(auto &it : a) {
            hsh1[it]++;
        }
        for(auto &it : b) {
            hsh2[it]++;
        }
        
        
        if(hsh1 != hsh2)
            return -1;
        
        int i = n - 1, j = m - 1;
        int ans = 0;
        while(i >= 0) {
            if(a[i] == b[j]) {
                i--, j--;
            }
            else{
                ans++, i--;
            }
        }
        
        return ans;
    }
};



//{ Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}
// } Driver Code Ends