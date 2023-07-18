//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    int lcs(string &s, string &t, int idx1, int idx2, vector<vector<int>> &dp)
    {
        int n = s.length();
        if(idx1 == n || idx2 == n)
            return 0;
        if(dp[idx1][idx2] != -1)
            return dp[idx1][idx2];
        if(s[idx1] == t[idx2] && idx1 != idx2) {
            return dp[idx1][idx2] = 1 + lcs(s, t, idx1 + 1, idx2 + 1, dp);
        }
        else {
            int way1 = lcs(s, t, idx1 + 1, idx2, dp);
            int way2 = lcs(s, t, idx1, idx2 + 1, dp);
            
            return dp[idx1][idx2] = max(way1, way2);
        }
    }
    
	public:
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    int n = str.length();
		    vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
		    
		    return lcs(str, str, 0, 0, dp);
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.LongestRepeatingSubsequence(str);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends