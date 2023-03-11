//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> solveQueries(int n, int num, vector<int> &a, vector<vector<int>> &q) {
        // code here
        
        vector<vector<int>> dp(n, vector<int> (n, 0));
        for(int i = 0; i < n; i++)
        {
            int freq = 0;
            for(int j = i; j < n; j++)
            {
                if(a[j] == a[i])
                    freq++;
                dp[i][j] = freq;
            }
        }
        
        vector<int> result(num, 0);
        for(int i = 0; i < num; i++)
        {
            int l = q[i][0], r = q[i][1], d = q[i][2];
            int ans = 0;
            for(int j = l; j <= r; j++)
            {
                if(dp[j][n - 1] == d)
                    ans++;
            }
            result[i] = ans;
        }
        
        return result;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int num;
        cin>>num;
        vector<int> A(N);
        for(int i=0;i<N;i++){
            cin>>A[i];
        }
        vector<vector<int>> Q(num, vector<int>(3));
        for(int i=0;i<num;i++){
            for(int j=0;j<3;j++){
                cin>>Q[i][j];
            }
        }
        Solution obj;
        vector<int> res = obj.solveQueries(N, num, A, Q);
        
        for(auto ele:res){
            cout<<ele<<" ";
        }
        cout<<endl;
    }
}

// } Driver Code Ends