    // <--------------------Jai Shree Babosa-------------------->

    #include <bits/stdc++.h>
    using namespace std;
    #define ll long long
    #define inf INT_MAX
    const int mod = 1e9 + 7;

    class Solution
    {

        void lowerbound(int lo, int hi, vector<int> &nums, int i, int &lower, int &upper, int &idx)
        {
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] + nums[i] >= lower)
                    hi = mid - 1, idx = mid;
                else
                    lo = mid + 1;
            }
        }
        void upperbound(int lo, int hi, vector<int> &nums, int i, int &lower, int &upper, int &idx)
        {
            while (lo <= hi)
            {
                int mid = lo + (hi - lo) / 2;

                if (nums[mid] + nums[i] <= upper)
                    lo = mid + 1, idx = mid;
                else
                    hi = mid - 1;
            }
        }

    public:
        long long countFairPairs(vector<int> &nums, int lower, int upper)
        {
            long long ans = 0;
            sort(nums.begin(), nums.end());

            int n = nums.size();

            for (int i = 0; i < n - 1; i++)
            {
                int idx1 = -1, idx2 = -1;

                lowerbound(i + 1, n - 1, nums, i, lower, upper, idx1);
                upperbound(i + 1, n - 1, nums, i, lower, upper, idx2);

                int len = idx2 - idx1 + 1;

                if (len > 0 && idx1 != -1 && idx2 != -1)
                    ans += len;
            }
            return ans;
        }
    };