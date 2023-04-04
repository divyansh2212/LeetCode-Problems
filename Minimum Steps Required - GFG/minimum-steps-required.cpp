//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string s) {
    // Write your code here.
    int n = s.length();
    
    unordered_map<char, int> streams;
    
    int i = 1;
    char last = s[0];
    
    while(i < n)
    {
        if(s[i] != last)
        {
            streams[last]++;
            last = s[i];
        }
        i++;
    }
    streams[last]++;
    
    return min(streams['a'], streams['b']) + 1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends