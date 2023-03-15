//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++
class Solution{
    //Complete the function and return minimum number of operations
    public:
    int specialPalindrome(string s1, string s2){
        //Code Here
        int n = s1.length(), m = s2.length();
        
        int ops = 1e9;
        for(int i = 0; i <= n - m; i++)
        {
            string copy_s1 = s1;
            
            int currOps = 0;
            for(int j = 0; j < m; j++)
            {
                if(copy_s1[j + i] != s2[j])
                    copy_s1[j + i] = s2[j], currOps++;
            }
                
                
            int l = 0, r = n - 1;
            while(l <= r)
            {
                if(copy_s1[l] != copy_s1[r])
                {
                    currOps++;
                    if(l >= i && l <= (i + m - 1) && r >= i && r <= (i + m - 1))
                    {
                        currOps = 1e9;
                        break;
                    }
                }
                    
                l++, r--;
            }
            
            ops = min(ops, currOps);
        }
        
        if(ops >= 1e9)
            ops = -1;
        
        return ops;
    }
};

//{ Driver Code Starts.


int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        Solution obj;
        int ans = obj.specialPalindrome(s1,s2);
        
        cout<<ans<<endl;
    }
}
// } Driver Code Ends