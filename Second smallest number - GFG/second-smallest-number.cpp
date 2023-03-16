//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
//User function Template for C++

class Solution{   
  public:
    string secondSmallest(int s, int d){
        
        string ans(d, '0');
        ans[0] = '1';
        s--;
        
        for(int i = d - 1; i >= 1; i--)
        {
            int to_add = min(s, 9);
            s -= to_add;
            ans[i] = char(to_add + ans[i]);
        }
        
        // 13333999
        // 13334899
        
        if(s > 8)
            return "-1";
        
        ans[0] = char(s + ans[0]);
        
        for(int i = d - 1; i > 0; i--)
        {
            if(ans[i - 1] != '9')
            {
                ans[i - 1] = char(ans[i - 1] + 1);
                ans[i] = char(ans[i] - 1);
                return ans;
            }
        }
        
        return "-1";
    }
};

//{ Driver Code Starts.

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.secondSmallest(S,D) << endl;
    }
    return 0; 
} 
// } Driver Code Ends