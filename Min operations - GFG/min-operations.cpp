//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int solve(int a, int b) {
        // code here
        
        bool flag1 = 0, flag2 = 0;
        for(int i = 0; i < 31; i++)
        {
            if(a & (1 << i) && (b & (1 << i)) == 0)
                flag1 = 1;
            else if(b & (1 << i) && (a & (1 << i)) == 0)
                flag2 = 1;
        }
        
        return flag1 + flag2;
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int a;
        scanf("%d",&a);
        
        
        int b;
        scanf("%d",&b);
        
        Solution obj;
        int res = obj.solve(a, b);
        
        printf("%d\n", res);
        
    }
}

// } Driver Code Ends