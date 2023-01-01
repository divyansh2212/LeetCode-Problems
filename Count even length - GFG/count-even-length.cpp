//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    const int mod = 1e9 + 7;
    
    long long binExp(long long a, long long b)
    {
        long long result = 1;
        
        while(b)
        {
            if(b & 1)
                result = (result * 1LL * a) % mod;
            a = (a * 1LL * a) % mod;
            b = (b >> 1);
        }
        return result;
    }
    
	public:
	int compute_value(int n)
	{
	    vector<long long> fact(n + 1, 1);
	    for(long long i = 2; i <= n; i++)
	        fact[i] = (i * 1LL * fact[i - 1]) % mod;
	    
	    // Code here
	    long long ans = 0, num = 1, deno = 1;
	    for(long long i = 0; i <= n; i++)
	    {
	        num *= fact[n];
	        num *= fact[n];
	        num = num % mod;
	        
	        deno *= fact[i];
	        deno = deno % mod;
	        deno *= fact[n - i];
	        deno = deno % mod;
	        deno *= fact[i];
	        deno = deno % mod;
	        deno *= fact[n - i];
	        deno = deno % mod;
	        
	        ans = (ans + (num * binExp(deno, mod - 2)) % mod) % mod;
	        num = 1, deno = 1;
	    }
	    
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		Solution ob;
		int ans = ob.compute_value(n);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends