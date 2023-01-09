#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
    bool check(vector<int> &stations, ll mid, ll k, int r)
    {
        int n = stations.size();

        ll curr = 0;
        vector<ll> add(n, 0);
        for (int i = 0; i < r; i++)
            curr += stations[i];

        for (int i = 0; i < n; i++)
        {
            if (i + r < n)
            {
                curr += stations[i + r];
                curr += add[i + r];
            }

            if (curr < mid)
            {
                ll need = mid - curr;
                if (need > k)
                    return false;
                k -= need;
                curr = mid;
                add[min(n - 1, i + r)] = need;
            }

            if (i - r >= 0)
            {
                curr -= stations[i - r];
                curr -= add[i - r];
            }
        }

        return true;
    }

public:
    long long maxPower(vector<int> &stations, int r, int k)
    {
        int n = stations.size();

        ll sum = 0;
        for (int i = 0; i < n; i++)
            sum += stations[i];

        ll lo = 0, hi = sum + k, mid, ans = 0;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (check(stations, mid, k, r))
                ans = mid, lo = mid + 1;
            else
                hi = mid - 1;
        }

        return ans;
    }
};