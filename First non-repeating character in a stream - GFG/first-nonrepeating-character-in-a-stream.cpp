//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string s){
		    // Code here
		    int n = s.length();
		    vector<int> hsh(26, 0);
		    string ans = "";
		    
		    int j = 0;
		    
		    for(int i = 0; i < n; i++)
		    {
		        hsh[s[i] - 'a']++;
		        while(j <= i && hsh[s[j] - 'a'] > 1) {
		            j++;
		        }
		        if(j > i) {
		            ans.push_back('#');
		        }
		        else {
		            ans.push_back(s[j]);
		        }
		    }
		    
		    return ans;    
		}
		

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends