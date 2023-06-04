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
public:
    long long matrixSumQueries(int n, vector<vector<int>> &queries)
    {
        int q = queries.size();
        set<int> row;
        set<int> col;
        ll ans = 0;
        for (int i = q - 1; i >= 0; i--)
        {
            int type = queries[i][0];
            int idx = queries[i][1];
            ll val = queries[i][2];

            if (type == 0)
            {
                if (row.count(idx)) continue;
                ans += val * (n - col.size());
                row.insert(idx);
            }
            else
            {
                if (col.count(idx)) continue;
                ans += val * (n - row.size());
                col.insert(idx);
            }
        }

        return ans;
    }
};