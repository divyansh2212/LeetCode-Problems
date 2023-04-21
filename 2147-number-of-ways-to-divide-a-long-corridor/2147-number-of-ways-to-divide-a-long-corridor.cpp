#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define vint vector<int>
#define vll vector<long long>
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
    ll solve(int idx, string &corridor)
    {
        int n = corridor.length();
        if (idx >= n)
            return 0;

        int seats = 0;
        ll ans = 0;
        for (int i = idx; i < n; i++)
        {
            if (corridor[i] == 'S')
                seats++;
            if (seats == 2)
            {
                ll curr = solve(i + 1, corridor);
                if (curr >= 0)
                {
                    ans += (curr);
                    if (i + 1 < n)
                        ans++;
                }

                ans = (ans % mod);
            }
            else if (seats > 2)
                break;
        }

        if (seats == 0)
            ans = -1e9;

        return ans;
    }

public:
    int numberOfWays(string corridor)
    {
        int n = corridor.length();
        int seats = 0;
        for (int i = 0; i < n; i++)
            if (corridor[i] == 'S')
                seats++;
        if (seats % 2 || seats == 0)
            return 0;
        if (seats == 2)
            return 1;

        int i = 0;
        ll ans = 1;
        seats = 0;

        while (i < n)
        {
            if (corridor[i] == 'S')
                seats++;

            if (seats == 2)
            {
                int plants = 0;
                i++;
                while (i < n && corridor[i] != 'S')
                {
                    plants++;
                    i++;
                }
                if (i < n)
                    ans = (ans * (plants + 1)) % mod;
                seats = 0;
            }
            else
                i++;
        }

        return ans;
    }
};