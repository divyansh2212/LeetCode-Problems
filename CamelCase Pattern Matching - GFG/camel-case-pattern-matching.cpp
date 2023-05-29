//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<string> CamelCase(int n, vector<string> dictionary, string pattern) {
        // code here
        vector<string> ans;
        vector<pair<string, int>> pairs;
        
        for(int i = 0; i < n; i++) {
            int m = dictionary[i].length();
            string curr = "";
            for(int j = 0; j < m; j++) {
                if(dictionary[i][j] >= 'A' && dictionary[i][j] <= 'Z') {
                    curr.push_back(dictionary[i][j]);
                }
            }
            pairs.push_back({curr, i});
        }
        
        for(int i = 0; i < n; i++)
        {
            string str = pairs[i].first;
            int m = str.length();
            int x = 0, y = 0;
            while(x < m && y < pattern.length()) {
                if(str[x] != pattern[y])
                    break;
                x++, y++;
            }
            if(y == pattern.length())
                ans.push_back(dictionary[pairs[i].second]);
        }
        
        if(ans.size() == 0)
            ans.push_back("-1");
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> Dictionary(N);
        for (int i = 0; i < N; i++) cin >> Dictionary[i];
        string Pattern;
        cin >> Pattern;
        Solution ob;
        vector<string> ans = ob.CamelCase(N, Dictionary, Pattern);
        sort(ans.begin(), ans.end());
        for (auto u : ans) cout << u << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends