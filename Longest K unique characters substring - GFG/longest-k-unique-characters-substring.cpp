//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        // your code here
        int n = s.length();
        unordered_map<char, int> hash;
        int ans = -1;
        
        int i = 0, j = 0;
        while(j < n) {
            hash[s[j]]++;
            while(hash.size() > k) {
                hash[s[i]]--;
                if(hash[s[i]] == 0) {
                    hash.erase(s[i]);
                }
                i++;
            }
            if(hash.size() == k) {
                ans = max(ans, j - i + 1);
            }
            j++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends