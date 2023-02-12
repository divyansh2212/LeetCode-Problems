// <--------------------Jai Shree Babosa-------------------->

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inf INT_MAX
const int mod = 1e9 + 7;

class Solution
{
public:
    long long countFairPairs(vector<int> &nums, int lower, int upper)
    {
        long long ans = 0;
        sort(nums.begin(), nums.end());

        int n = nums.size();

        for (int i = 0; i < n - 1; i++)
        {
            int idx1 = -1, idx2 = -1, lo = i + 1, hi = n - 1;

            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] + nums[i] >= lower)
                    hi = mid - 1, idx1 = mid;
                else
                    lo = mid + 1;
            }

            lo = i + 1, hi = n - 1;
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] + nums[i] <= upper)
                    lo = mid + 1, idx2 = mid;
                else
                    hi = mid - 1;
            }

            int len = idx2 - idx1 + 1;

            if (len > 0 && idx1 != -1 && idx2 != -1)
                ans += len;
        }
        return ans;
    }
};