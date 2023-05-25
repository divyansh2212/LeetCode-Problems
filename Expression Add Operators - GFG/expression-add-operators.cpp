//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
    
    void solve(int idx, string &s, int &target, string curr, vector<string> &ans)
    {
        int n = s.length();
        curr.push_back(s[idx]);
        
        if(idx == n - 1) {
            
            bool flag = true;
            for(int i = 0; i < curr.length() - 1 && flag; i++) {
                if(curr[i] == '+' || curr[i] == '-' || curr[i] == '*') {
                    if(curr[i + 1] == '0' && i + 2 < curr.length() && curr[i + 2] >= '0' && curr[i + 2] <= '9')
                        flag = false;
                }
            }
            
            if(!flag) return;
            
            // cout << curr << " ";
            int i = 0;
            long num = 0;
            vector<pair<long, char>> temppairs;
            while(i < curr.length()) {
                
                if(i == curr.length() - 1) {
                    num = (num * 10) + (curr[i] - '0');
                    temppairs.push_back({num, ' '});
                }
                
                else if(curr[i] == '+' || curr[i] == '-' || curr[i] == '*') {
                    temppairs.push_back({num, curr[i]});
                    num = 0;
                }
                else {
                    num = (num * 10) + (curr[i] - '0');
                }
                i++;
            }
            
            vector<pair<long, char>> pairs;
            i = 0;
            while(i < temppairs.size()) {
                
                if(temppairs[i].second == '+') {
                    pairs.push_back({temppairs[i].first, '+'});
                }
                else if(temppairs[i].second == '-') {
                    pairs.push_back({temppairs[i].first, '-'});
                }
                else if(temppairs[i].second == ' ') {
                    pairs.push_back({temppairs[i].first, ' '});
                }
                
                else {
                    long num = 1;
                    while(temppairs[i].second == '*') {
                        num *= temppairs[i].first;
                        i++;
                    }

                    num *= temppairs[i].first;
                    pairs.push_back({num, temppairs[i].second});
                }
                i++;
            }
            
            long number = 0;
            for(int i = 0; i < pairs.size() - 1; i++) {
                if(pairs[i].second == '+') {
                    if(i == 0)
                        number = pairs[i].first + pairs[i + 1].first;
                    else
                        number = number + pairs[i + 1].first;
                }
                else if(pairs[i].second == '*') {
                    if(i == 0)
                        number = pairs[i].first * pairs[i + 1].first;
                    else
                        number = number * pairs[i + 1].first;
                }
                else if(pairs[i].second == '-') {
                    if(i == 0)
                        number = pairs[i].first - pairs[i + 1].first;
                    else
                        number = number - pairs[i + 1].first;
                }
            }
            
            if(pairs.size() == 1)
                number = pairs[0].first;
            
            if(number == target)
                ans.push_back(curr);
            
            return;
        }
        
        solve(idx + 1, s, target, curr, ans);
        
        curr.push_back('+');
        solve(idx + 1, s, target, curr, ans);
        curr.pop_back();
        
        curr.push_back('-');
        solve(idx + 1, s, target, curr, ans);
        curr.pop_back();
        
        curr.push_back('*');
        solve(idx + 1, s, target, curr, ans);
        curr.pop_back();
        
        // curr.pop_back();
    }
    
  public:
    vector<string> addOperators(string s, int target) {
        // code here
        vector<string> ans;
        string curr = "";
        
        solve(0, s, target, curr, ans);
        // if(ans.size() == 0)
        //     ans.push_back("");
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int target;
        string S;
        cin >> S >> target;

        Solution obj;
        vector<string> ans = obj.addOperators(S, target);
        sort(ans.begin(), ans.end());
        for (auto &it : ans) cout << it << ' ';
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends