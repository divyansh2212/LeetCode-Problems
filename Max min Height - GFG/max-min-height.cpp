//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution
{
    
    bool check(int k, int w, vector<int> a, long long mid)
    {
        int n = a.size();
        for(int i = 0; i < n; i++)
        {
            if(a[i] < mid)
            {
                long long temp = mid - a[i];
                if(temp > k)
                    return false;
                a[i] = mid;
                k -= temp;
                for(int j = i + 1; j < n && j < i + w; j++)
                    a[j] += temp;
            }
        }
        return true;
    }
    
    public:
        long long int maximizeMinHeight(int n,int k,int w,vector <int> &a)
        {
            // code here
            long long low = 1, high = INT_MAX, ans = -1;
            
            while(low <= high)
            {
                long long mid = low + (high - low) / 2;
                if(check(k, w, a, mid))
                    ans = mid, low = mid + 1;
                else
                    high = mid - 1;
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
        int n,k,w;
        cin>>n>>k>>w;
        vector <int> a(n);
        for(auto &j:a)
            cin>>j;
        Solution s;
        cout<<s.maximizeMinHeight(n,k,w,a)<<endl;
    }
    return 0;
}
// } Driver Code Ends