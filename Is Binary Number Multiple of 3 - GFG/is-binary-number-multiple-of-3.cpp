//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
    const int mod = 3;
    
    int binExp(int a, int b)
    {
        int result = 1;
        while(b) {
            if(b & 1)
                result = (result * a) % mod;
            a = (a * a) % mod;
            b = (b >> 1);
        }
        return result;
    }
    
public:	
		
	int isDivisible(string s){
	    //complete the function here
	    int n = s.length();
	    
	    int ans = 0;
	    
	    for(int i = n - 1, power = 0; i >= 0; i--, power++) {
	        if(s[i] == '1')
	            ans = (ans + binExp(2, power)) % mod;
	    }
	    
	   // cout << ans;
	    if(ans >= 1)
	        return 0;
	    
	    return 1;
	}

};

//{ Driver Code Starts.
int main(){
    
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        Solution ob;
        cout << ob.isDivisible(s) << endl;
    }
return 0;
}


// } Driver Code Ends