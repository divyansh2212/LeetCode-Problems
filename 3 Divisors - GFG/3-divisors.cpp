//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
    vector<int> threeDivisors(vector<long long> query, int q)
    {
        vector<bool> is_prime(1e6 + 10, true);
        is_prime[0] = false, is_prime[1] = false;
        
        for(int i = 2; i < 1e6 + 10; i++)
            if(is_prime[i])
                for(int j = 2 * i; j < 1000010; j += i)
                    is_prime[j] = false;
        // Write your code here
        vector<int> ans(q, 0);
        for(int i = 0; i < q; i++)
        {
            for(long long j = 2; j*j <= query[i]; j++)
                if(is_prime[j])
                    ans[i]++;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while(t--){
        int q;cin>>q;
        vector<long long> query(q);
        for(int i=0;i<q;i++){
            cin>>query[i];
        }
        Solution ob;
            
        vector<int> ans = ob.threeDivisors(query,q);
        for(auto cnt : ans) {
            cout<< cnt << endl;
        }
    }
    return 0;
}
// } Driver Code Ends