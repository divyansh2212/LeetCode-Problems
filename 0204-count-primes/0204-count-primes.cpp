class Solution {
public:
    int countPrimes(int n) {
        vector<bool> is_prime(n + 1, true);
        is_prime[0] = is_prime[1] = false;
        
        int ans = 0;
        
        for(int i = 2; i < n; i++) {
            if(is_prime[i]) {
                ans++;
                for(int j = 2*i; j <= n; j+=i) {
                    is_prime[j] = false;
                }
            }
        }
        
        return ans;
    }
};