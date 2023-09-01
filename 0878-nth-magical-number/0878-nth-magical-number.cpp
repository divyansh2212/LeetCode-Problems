class Solution {
    
    const int mod = 1e9 + 7;
    
    bool check(int n, int a, int b, long long mid)
    {
        long long f1 = mid / a;
        long long f2 = mid / b;
        long long lcm = (a* 1LL * b) / __gcd(a, b);
        
        f1 -= mid / lcm;
        
        return (f1 + f2) >= n;
    }
    
public:
    int nthMagicalNumber(int n, int a, int b) {
        if(a == 1 || b == 1)
            return n;
        long long lo = 1, hi = 1e18, ans = 1e18;
        
        while(lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if(check(n, a, b, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else
                lo = mid + 1;
        }
        
        return (ans % mod);
    }
};