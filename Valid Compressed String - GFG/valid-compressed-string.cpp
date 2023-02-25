//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkCompressed(string s, string t) {
        // code here
        int i = 0, j = 0;
        int n = s.length(), m = t.length();
        
        while(i < n && j < m)
        {
            if(t[j] >= 'A' && t[j] <= 'Z')
            {
                if(s[i] != t[j])
                    return 0;
                else
                    i++, j++;
            }
            else
            {
                string numeric = "";
            
                while(j < m && t[j] >= '0' && t[j] <= '9')
                {   
                    numeric.push_back(t[j]);
                    j++;
                }
                
                int count = stoi(numeric);
                while(i < n && count > 0)
                    i++, count--;
                
                if(count > 0)
                    return 0;
            }
        }
        
        if(i != n && j != m)
            return 0;
        
        return 1;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        
        cin>>S>>T;

        Solution ob;
        cout << ob.checkCompressed(S,T) << endl;
    }
    return 0;
}
// } Driver Code Ends