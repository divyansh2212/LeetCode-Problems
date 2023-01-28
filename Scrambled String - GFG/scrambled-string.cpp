//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

//Back-end complete function Template for C++

class Solution{
    map<string, bool> mp;
    public:
    bool isScramble(string s1, string s2){
        
        int n = s1.length();
        
        if(mp.find(s1 + s2) != mp.end())
            return mp[s1 + s2];
        
        if(s1 == s2)
            return mp[s1 + s2] = true;
        
        for(int i = 1; i < n; i++)
        {
            string a = s1.substr(0, i);
            string b = s2.substr(0, i);
            
            string c = s1.substr(i, n - i);
            string d = s2.substr(i, n - i);
            
            if(isScramble(a, b) && isScramble(c, d))
                return mp[s1 + s2] = true;
                
            string e = s1.substr(0, i);
            string f = s2.substr(n - i, i);
            
            string g = s1.substr(i, n - i);
            string h = s2.substr(0, n - i);
            
            if(isScramble(e, f) && isScramble(g, h))
                return mp[s1 + s2] = true;
        }
        
       return mp[s1 + s2] = false;
    }    
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        string S1, S2;
        cin>>S1>>S2;
        Solution ob;
        
        if (ob.isScramble(S1, S2)) {
            cout << "Yes";
        }
        else {
            cout << "No";
        }
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends