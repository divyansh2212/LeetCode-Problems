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
      vector<long long> weights(n, 0);
      for(int i = 0; i < n; i++)
      {
          if(edge[i] == -1)
            continue;
        
        weights[edge[i]] += i;
      }
      
      int ansNode = 0;
      long long maxWeight = -1;
      for(int i = 0; i < n; i++)
      {
          if(weights[i] >= maxWeight){
              maxWeight = weights[i];
              ansNode = i;
          }
      }
      
      return ansNode;
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