//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal
// } Driver Code Ends


int countRev (string s)
{
    int ans = 0;
    int n = s.length();
    if(n % 2)
        return -1;
    int open = 0;
    
    for(int i = 0; i < n; i++) {
        if(s[i] == '{')
            open++;
        else if(s[i] == '}') {
            if(open > 0) {
                open--;
            }
            else {
                open++;
                ans++;
            }
        }
    }
    
    ans += open / 2;
    if(open % 2)
        open++;
    return ans;
}