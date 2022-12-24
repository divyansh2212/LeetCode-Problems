class Solution {
    const int mod = 1e9 + 7;
public:
    int numTilings(int n) {
        if(n <= 2)
            return n;
        if(n == 3)
            return 5;
        
        int a = 1, b = 2, c = 5;
        
        int curr = 3;
        
        while(curr < n)
        {
            int prev = b;
            b = c;
            c = ((2 * 1LL * c) % mod + 0LL + a) % mod;
            a = prev;
            curr++;
        }
        
        return c;
    }
};