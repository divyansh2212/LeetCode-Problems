//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    
    int binExp(int a, int b, int m)
    {
        int ans = 1;
        
        while(b)
        {
            if(b & 1)
                ans = (ans * 1LL * a) % m;
            a = (a * 1LL * a) % m;
            b = (b >> 1);
        }
        
        return ans;
    }
    
    public:
        int modulo(string s,int m)
        {
            //code here
            int ans = 0;

            for(int i = s.length() - 1, power = 0; i >= 0; i--, power++)
            {
                if(s[i] == '1')
                    ans = (ans + 0LL + binExp(2, power, m)) % m;
            }
            
            return ans;
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
        int m;
        cin>>s>>m;
        Solution a;
        cout<<a.modulo(s,m)<<endl;
    }
    return 0;
}
// } Driver Code Ends