//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &mat, int r, int c){
        // code here          
        sort(mat.begin(), mat.end());
        int lo = mat[0][0], hi = mat[r - 1][c - 1], ans;
        
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            int elements = 0;
            bool flag = false;
            for(int i = 0; i < r; i++) {
                int lb = lower_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
                elements += lb;
                if(mat[i][lb] == mid) {
                    flag = true;
                }
            }
            if(elements > (r*c/2)) {
                // if(flag)
                    
                hi = mid - 1;
            }
            else {
                ans = mid;
                lo = mid + 1;
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
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    }
    return 0;
}
// } Driver Code Ends