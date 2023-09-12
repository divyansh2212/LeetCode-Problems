//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int minFlips (string s);
int32_t main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;

        cout << minFlips (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends


int minFlips (string s)
{
    int n = s.length();
    int ans1 = 0;
    
    for(int i = 0; i < n; i++) {
        if(i % 2) {
            if(s[i] == '0')
                ans1++;
            else
                continue;
        }
        else {
            if(s[i] == '1')
                ans1++;
            else
                continue;
        }
    }
    
    
    int ans2 = 0;
    
    for(int i = 0; i < n; i++) {
        if(i % 2 == 0) {
            if(s[i] == '0')
                ans2++;
            else
                continue;
        }
        else {
            if(s[i] == '1')
                ans2++;
            else
                continue;
        }
    }
    
    return min(ans1, ans2);
}