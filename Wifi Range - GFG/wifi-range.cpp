//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        
        for(int i = 0; i < n; i++)
        {
            if(s[i] == '0')
            {
                bool flag = false;
                for(int j = i + 1; j <= i + x && !flag && j < n; j++)
                    if(s[j] == '1')
                        flag = true;
                
                for(int j = i - 1; j >= i - x && !flag && j >= 0; j--)
                    if(s[j] == '1')
                        flag = true;
                if(!flag)
                    return false;
            }
        }
        
        return true;
        
    }
};

//{ Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}

// } Driver Code Ends