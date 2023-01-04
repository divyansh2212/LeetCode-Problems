class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> is_prime(1e6 + 1, true);
        is_prime[0] = false, is_prime[1] = false;
        
        for(int i = 2; i <= 1e6; i++)
            if(is_prime[i])
                for(int j = 2 * i; j <= 1e6; j += i)
                    is_prime[j] = false;
        
        vector<int> primes;
        for(int i = left; i <= right; i++)
            if(is_prime[i])
                primes.push_back(i);
        
        if(primes.size() < 2)
            return {-1, -1};
        
        vector<int> ans;
        int diff = 1e9;
        for(int i = 1; i < primes.size(); i++)
        {
            if(primes[i] - primes[i - 1] < diff)
            {
                ans = {primes[i - 1], primes[i]};
                diff = primes[i] - primes[i - 1];
            }
        }
        return ans;
    }
};