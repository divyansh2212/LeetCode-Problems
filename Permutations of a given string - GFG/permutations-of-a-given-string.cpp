//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    
    void solve(int idx, unordered_set<string> &ans, string &curr, string &s)
    {
        int n = s.length();
        if(idx == n) {
            ans.insert(curr);
            return;
        }
     
        for(int i = idx; i < n; i++) {
            if(i > idx && s[i] == s[i - 1])
                continue;
            curr.push_back(s[i]);
            swap(s[i], s[idx]);
            solve(idx + 1, ans, curr, s);
            curr.pop_back();
            swap(s[i], s[idx]);
        }
    }
    
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(), s.end());
		    unordered_set<string> ans;
		    string curr = "";
		    
		    solve(0, ans, curr, s);
		    
		    vector<string> result;
		    for(auto &x : ans) {
		        result.push_back(x);
		    }
		    
		    return result;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    sort(ans.begin(),ans.end());
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends