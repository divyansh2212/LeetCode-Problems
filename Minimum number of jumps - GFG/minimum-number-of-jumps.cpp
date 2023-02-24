//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int jumps = 0;
        
        int i = 0;
        while(i < n)
        {
            int maxJump = arr[i];
            if(i + maxJump >= n - 1)
                break;
            if(maxJump == 0)
                return -1;
            jumps++;
            int bestone = arr[i + 1] + 1;
            
            int idx = i + 1;
            for(int j = i + 1; j < n, maxJump > 0; j++, maxJump--)
            {
                if(arr[j] > bestone - 1)
                {
                    bestone = max(bestone - 1, arr[j]);
                    idx = j;
                }
                else
                    bestone--;
            }
            
            i = idx;
        }
        
        return jumps + 1;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends