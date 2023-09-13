//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
    
    void solve(int idx, int points, vector<string> &ans, string curr, string &s)
    {
        int n = s.length();
        
        if(points == 0) {
            if(idx == n)
                return;
            
            int len = n - idx;
            if(len > 4)
                return;
            string temp = "";
            for(int i = idx; i < n; i++) {
                if(i > idx && s[idx] == '0')
                    return;
                temp.push_back(s[i]);
            }
            int val = stoi(temp);
            if(val > 255)
                return;
            
            ans.push_back(curr + temp);
            return;
        }
        
        if(idx == n)
            return;
        
        string temp = "";
        for(int i = idx; i < min(idx + 3, n); i++) {
            if(i > idx && s[idx] == '0')
                break;
            temp.push_back(s[i]);
            int val = stoi(temp);
            if(val > 255)
                break;
            temp.push_back('.');
            solve(i + 1, points - 1, ans, curr + temp, s);
            temp.pop_back();
        }
        
    }
    
  public:
    vector<string> genIp(string &s) {
        int n = s.length();
        
        if(n < 4)
            return {"-1"};
            
        vector<string> ans;
        string curr = "";
        
        solve(0, 3, ans, curr, s);
        
        return ans;
    }

};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        string s;
        cin >> s;

        /*generating naively*/
        Solution obj;
        vector<string> str = obj.genIp(s);
        sort(str.begin(), str.end());
        if(str.size()==0)
            cout << -1 << "\n";
        else{
            for (auto &u : str) {
                cout << u << "\n";
            }
        }
    }
}
// } Driver Code Ends