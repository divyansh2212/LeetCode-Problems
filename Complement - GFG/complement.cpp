//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    vector<int> findRange(string str, int n) {
        
        int ones = 0;
        for(int i = 0; i < n; i++)
            if(str[i] == '1')
                ones++;
                
        if(ones == n)
            return {-1};
            
        int i = 0, j = 0;
        int l = 0, r = 0;
        int max_so_far = 0, currSum = 0;
        
        while(j < n)
        {
            if(str[j] == '0')
                currSum++;
            else
                currSum--;
            if(currSum < 0)
            {
                currSum = 0;
                j++;
                i = j;
            }
            
            else if(currSum > max_so_far)
            {
                max_so_far = currSum;
                l = i, r = j;
                j++;
            }
            else
                j++;
                
        }
        
        return {l + 1, r + 1};    
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        Solution ob;
        auto ans = ob.findRange(s, n);

        if (ans.size() == 1) {
            cout << ans[0] << "\n";
        } else {
            cout << ans[0] << " " << ans[1] << "\n";
        }
    }
    return 0;
}
// } Driver Code Ends