//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
  public:
    string secFrequent (string arr[], int n)
    {
        int maxi1 = 0;
        string ans1 = "";
        
        int maxi2 = 0;
        string ans2 = "";
        
        unordered_map<string, int> freq;
        
        for(int i = 0; i < n; i++) {
            freq[arr[i]]++;
            if(freq[arr[i]] > maxi1) {
                if(arr[i] == ans1) {
                    maxi1 = freq[arr[i]];
                    continue;
                }
                maxi2 = maxi1;
                ans2 = ans1;
                maxi1 = freq[arr[i]];
                ans1 = arr[i];
            }
            else if(freq[arr[i]] > maxi2) {
                maxi2 = freq[arr[i]];
                ans2 = arr[i];
            }
        }
        
        return ans2;
    }
};

//{ Driver Code Starts.
int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n; cin >> n;
        string arr[n];
        for (int i = 0; i < n; ++i)
            cin >> arr[i];
        Solution ob;
        cout << ob.secFrequent (arr, n) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends