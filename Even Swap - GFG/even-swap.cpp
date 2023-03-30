//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
        vector <int> lexicographicallyLargest(vector <int> &a, int n)
        {
            int i = 0;
            
            while(i < n)
            {
                int start = i;
                while(i < n && a[start] % 2 == a[i] % 2)
                {
                    i++;
                }
                sort(a.begin() + start, a.begin() + i);
                reverse(a.begin() + start, a.begin() + i);
            }
            
            return a;
        }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        vector <int> b=s.lexicographicallyLargest(a,n);
        for(auto i:b)
            cout<<i<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends