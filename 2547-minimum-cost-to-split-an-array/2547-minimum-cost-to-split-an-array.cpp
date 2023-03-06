// <--------------------Jai Shree Babosa-------------------->

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
    ll calc(int idx, vector<int> &nums, int &k, vector<int> &dp)
    {
        int n = nums.size();
        if (idx == n)
            return 0;
        if (dp[idx] != -1)
            return dp[idx];
        vector<int> hash(n, 0);
        ll repeated = 0;
        ll ans = 1e15;
        for (int i = idx; i < n; i++)
        {
            hash[nums[i]]++;
            if (hash[nums[i]] == 2)
                repeated += 2;
            else if (hash[nums[i]] > 2)
                repeated++;
            ans = min(ans, repeated + k + calc(i + 1, nums, k, dp));
        }

        return dp[idx] = ans;
    }

public:
    int minCost(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, -1);
        return (int)calc(0, nums, k, dp);
    }
};