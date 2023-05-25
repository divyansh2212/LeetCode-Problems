class Solution {
    const int mod = 1e9 + 7;
    
    int binExp(int a, int b)
    {
        int result = 1;
        while(b)
        {
            if(b & 1)
                result = (result * 1LL * a) % mod;
            b = (b >> 1);
            a = (a * 1LL *a) % mod;
        }
        return result;
    }
    
    int nCr(int n, int r, vector<int> &fact)
    {
        if(r > n)
            return 0;
        int deno = (fact[r] * 1LL * fact[n-r]) % mod;
        return (fact[n] * 1LL * binExp(deno, mod - 2)) % mod;
    }
 
public:
    int threeSumMulti(vector<int>& arr, int target) {
    
        int n = arr.size(), ans = 0;
        
        vector<int> freq(101, 0);
        vector<int> fact(3001, 1);
        for(int i = 2; i < 3001; i++)
            fact[i] = (fact[i - 1] * 1LL * i) % mod;
        
        for(int i = 0; i < n; i++)
            freq[arr[i]]++;
        
        for(int i = 0; i <= 100; i++)
        {
            if(freq[i] == 0)
                continue;
            for(int j = i; j <= 100; j++)
            {
                if(freq[j] == 0)
                    continue;
                for(int k = j; k <= 100; k++)
                {
                    if(freq[k] == 0)
                        continue;
                    if(i + j + k == target) {
                        if(i == j && j == k) {
                            ans = (ans + 0LL + nCr(freq[i], 3, fact)) % mod;
                        }
                        else if(i == j) {
                            ans = (ans + 0LL + (nCr(freq[i], 2, fact) *1LL* freq[k]) % mod) % mod;
                        }
                        else if(k == j) {
                            ans = (ans + 0LL + (nCr(freq[k], 2, fact) *1LL* freq[i]) % mod) % mod;
                        }
                        else if(i == k) {
                            ans = (ans + 0LL + (nCr(freq[i], 2, fact) *1LL* freq[j]) % mod) % mod;
                        }
                        else {
                            ans = (ans + 0LL + (freq[i] *1LL*freq[j]*freq[k]) % mod) % mod;
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};