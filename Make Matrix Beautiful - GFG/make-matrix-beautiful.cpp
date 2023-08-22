//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    public:
    //Function to find minimum number of operations that are required 
    //to make the matrix beautiful.
    int findMinOpeartion(vector<vector<int> > matrix, int n)
    {
        // code here 
        int ans = 0;
        int maxi = 0;
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += matrix[i][j];
            }
            maxi = max(maxi, sum);
        }
        for(int j = 0; j < n; j++) {
            int sum = 0;
            for(int i = 0; i < n; i++) {
                sum += matrix[i][j];
            }
            // cout << sum << " ";
            maxi = max(maxi, sum);
        }
        
        for(int i = 0; i < n; i++) {
            int sum = 0;
            for(int j = 0; j < n; j++) {
                sum += matrix[i][j];
            }
            // cout << maxi - sum << " ";
            ans += (maxi - sum);
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
        int n;
        cin>>n;
        vector<vector<int> > matrix (n,vector<int>(n));
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>matrix[i][j];
        Solution ob;
        cout << ob.findMinOpeartion(matrix, n) << endl;
    }
    return 0;
}


// } Driver Code Ends