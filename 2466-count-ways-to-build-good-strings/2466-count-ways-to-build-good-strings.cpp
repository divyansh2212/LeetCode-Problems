#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{

    ll ways(int &low, int &high, int &zero, int &one, int length, vector<ll> &dp)
    {
        if (dp[length] != -1)
            return dp[length];
        ll way1 = 0, way2 = 0;
        if (zero + length <= high)
            way1 = ways(low, high, zero, one, zero + length, dp);
        if (zero + length <= high && zero + length >= low)
            way1++;
        if (one + length <= high)
            way2 = ways(low, high, zero, one, one + length, dp);
        if (one + length <= high && one + length >= low)
            way2++;

        return dp[length] = (way1 + way2) % mod;
    }

public:
    int countGoodStrings(int low, int high, int zero, int one)
    {
        vector<ll> dp(1e5 + 10, -1);
        return ways(low, high, zero, one, 0, dp);
    }
};