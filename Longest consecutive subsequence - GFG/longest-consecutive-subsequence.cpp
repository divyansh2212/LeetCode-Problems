//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int arr[], int n)
    {
        vector<bool> exist(1e5 + 1, false);
        for(int i = 0; i < n; i++) {
            exist[arr[i]] = true;
        }
        int ans = 1;
        
        for(int i = 0; i < n; i++) {
            if(arr[i] == 0 || exist[arr[i] - 1] == false) {
            
                int num = arr[i];
                while(exist[num]) {
                    num++;
                }
                
                ans = max(ans, num - arr[i]);
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
 
// Driver program
int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  Solution obj;
  cout<<obj.findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}
// } Driver Code Ends