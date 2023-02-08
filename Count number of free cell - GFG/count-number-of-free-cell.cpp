//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  vector<long long int> countZero(int n, int k, vector<vector<int>>& arr){
      //Code Here
      long long ans = n * 1LL * n;
      vector<long long int> result;
      
      vector<bool> row(n, false);
      vector<bool> col(n, false);
      
      int currrow = n, currcol = n;
      
      for(int i = 0; i < k; i++)
      {
          int r = arr[i][0], c = arr[i][1];
          r--, c--;
          
          if(row[r] == false)
          {
              row[r] = true;
              currrow--;
              ans -= currcol;
          }
          if(col[c] == false)
          {
              col[c] = true;
              currcol--;
              ans -= currrow;
          }
          result.push_back(ans);
      }
      
      return result;
  }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<vector<int>> arr(k,vector<int>(2));
        for(int i=0;i<k;i++){
            int x, y;
            cin>>x>>y;
            arr[i][0] = x;
            arr[i][1] = y;
        }
        Solution ob;
        vector<long long int> ans = ob.countZero(n,k,arr);
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;    
    }
    
    return 0;
}


// } Driver Code Ends