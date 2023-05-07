//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:
    string stringMirror(string str){
        // Code here
        string ans = "";
        ans.push_back(str[0]);
        string rev = ans;
                reverse(rev.begin(), rev.end());
                ans += rev;
        
        string curr = "";
        curr.push_back(str[0]);
        
        for(int i = 1; i < str.length(); i++)
        {
            curr.push_back(str[i]);
            if(curr < ans)
            {
                ans = curr;
                string rev = ans;
                reverse(rev.begin(), rev.end());
                ans += rev;
            }
            else{
                break;
            }
        }
        
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        Solution ob;
        string res=ob.stringMirror(str);
        cout<<res<<endl;
    }
}
// } Driver Code Ends