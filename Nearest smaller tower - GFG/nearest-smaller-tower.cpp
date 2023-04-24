//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr)
    {
        // code here
        int n = arr.size();
        stack<pair<int, int>> st;
        vector<int> ans(n, 0);
        
        for(int i = 0; i < n; i++)
        {
            while(st.size() && st.top().first >= arr[i])
                st.pop();
            
            if(st.size() == 0)
                ans[i] = -1;
            else
                ans[i] = st.top().second;
            
            st.push({arr[i], i});
        }
        
        while(st.size()) st.pop();
        st.push({arr[n - 1], n - 1});
        
        for(int i = n - 2; i >= 0; i--)
        {
            while(st.size() && st.top().first >= arr[i])
                st.pop();
            if(st.size() == 0)
                st.push({arr[i], i});
            else
            {
                while(st.size() && st.top().first >= arr[i])
                    st.pop();
                    
                if(st.size())
                {
                    if(ans[i] == -1)
                        ans[i] = st.top().second;
                    else if(st.top().second - i < i - ans[i])
                        ans[i] = st.top().second;    
                    else if(st.top().second - i == i - ans[i] && arr[st.top().second] < arr[ans[i]])
                    {
                    
                            ans[i] = st.top().second;
                    }
                }
                
                st.push({arr[i], i});
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        Solution ob;
        vector<int> ans = ob.nearestSmallerTower(v);
        for (int i = 0; i < n; i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends