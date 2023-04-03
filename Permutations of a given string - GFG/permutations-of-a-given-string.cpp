//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
    void solve(vector<string> &ans, string &s, string &curr, vector<bool> &visited)
    {
        if(curr.length() == s.length())
        {
            ans.push_back(curr);
            return;
        }
        
        for(int i = 0; i < s.length(); i++)
        {
            if(!visited[i])
            {
                if(i > 0 && visited[i - 1] == false && s[i] == s[i - 1])
                    continue;
                visited[i] = true;
                curr.push_back(s[i]);
                solve(ans, s, curr, visited);
                curr.pop_back();
                visited[i] = false;
            }
        }
        
    }
    
	public:
		vector<string>find_permutation(string s)
		{
		    // Code here there
		    sort(s.begin(), s.end());
		    vector<string> ans;
		    string curr = "";
		    
		    vector<bool> visited(s.length(), false);
		    
		    solve(ans, s, curr, visited);
		    
		    sort(ans.begin(), ans.end());
		    
		    return ans;
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
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends