//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
    
    bool solve(int currSum, int a[], int &n, int k, vector<bool> &visited, int &eachPart)
    {
        if(k == 1)
        {
            int curr = 0;
            for(int i = 0; i < n; i++)
                if(!visited[i])
                    curr += a[i];
            
            return (curr == eachPart);
        }
        
        if(currSum == eachPart)
            return solve(0, a, n, k - 1, visited, eachPart);
            
        
        bool flag = false;
        for(int i = 0; i < n; i++)
        {
            if(currSum + a[i] <= eachPart && visited[i] == false)
            {
                visited[i] = true;
                flag |= solve(currSum + a[i], a, n, k, visited, eachPart);
                visited[i] = false;
                if(flag)
                    return true;
            }
        }
        
        return flag;
    }
    
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         if(k == 1)
            return true;
         
         int sum = 0;
         for(int i = 0; i < n; i++)
            sum += a[i];
            
        if(sum % k) return false;
        sum /= k;
         
         vector<bool> visited(n, false);
         
         return solve(0, a, n, k, visited, sum);
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
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends