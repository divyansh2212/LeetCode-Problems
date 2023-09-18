//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    
    bool check(vector<int> &hsh1, vector<int> &hsh2) {
        for(int i = 0; i < 26; i++) {
            if(hsh1[i] > hsh2[i])
                return false;
        }
        return true;
    }
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        // Your code here
        int n = s.length(), m = p.length();
        vector<int> hsh1(26, 0);
        for(int i = 0; i < m; i++) {
            hsh1[p[i] - 'a']++;
        }
        
        int len = 1e9;
        int idx = 1e9;
        
        int i = 0, j = 0;
        vector<int> hsh2(26, 0);
        while(j < n) {
            hsh2[s[j] - 'a']++;
            while(check(hsh1, hsh2)) {
                if(j - i + 1 < len) {
                    len = j - i + 1;
                    idx = i;
                }
                else if(j - i + 1 == len && i < idx) {
                    idx = i;
                }
                hsh2[s[i] - 'a']--;
                i++;
            }
            j++;
        }
        
        if(len == 1e9)
            return "-1";
        return s.substr(idx, len);
    }
};

//{ Driver Code Starts.
int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        Solution obj;
        cout<<obj.smallestWindow(s, pat)<<endl;
        
    }
	return 0;
}
// } Driver Code Ends