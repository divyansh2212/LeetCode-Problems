//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution
{
  public:
  int maxWeightCell(int n, vector<int> edge)
  {
      // code here
      int ans = 0, ansIdx = 0;
      vector<int> hash(n, 0);
      for(int i = 0; i < n; i++)
      {
        if(edge[i] == -1)
            continue;
        
        hash[edge[i]] += i;
        
        if(hash[edge[i]] > ans)
        {
            ans = hash[edge[i]];
            ansIdx = edge[i];
        }
        else if(ans == hash[edge[i]])
            ansIdx = max(ansIdx, edge[i]);
      }
      
      return ansIdx;
  }
};

//{ Driver Code Starts.
int main(){
   int tc;
   cin >> tc;
   while(tc--){
      int N;
      cin >> N;
      vector<int> Edge(N);
      for(int i=0;i<N;i++){
        cin>>Edge[i];
      }
      Solution obj;
      int ans=obj.maxWeightCell(N, Edge);
      cout<<ans<<endl;
   }
   return 0;
}
// } Driver Code Ends