//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    string reverseEqn (string s)
        {
            reverse(s.begin(), s.end());
            int i = 0;
            while(i < s.length())
            {
                int j = i;
                string temp = "";
                while(s[j] >= '0' && s[j] <= '9')
                {
                    temp.push_back(s[j]);
                    j++;
                }
                reverse(s.begin() + i, s.begin() + j);
                i = j;
                i++;
            }
            return s;
        }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        Solution ob;
        cout <<ob.reverseEqn (s) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends