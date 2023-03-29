//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
    public:
    int countSubstring(string s)
    {
        // code here
        int n = s.length();
        int ans = 0;
        
        for(int i = 0; i < n; i++)
        {
            int lower = 0, higher = 0;
            for(int j = i; j < n; j++)
            {
                if(s[j] >= 'A' && s[j] <= 'Z')
                    higher++;
                else
                    lower++;
                ans += (higher == lower);
            }
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
        string S;
        cin>>S;
        Solution obj;
        cout<<obj.countSubstring(S)<<endl;
    }
}  
// } Driver Code Ends