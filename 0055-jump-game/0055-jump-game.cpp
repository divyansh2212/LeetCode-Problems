// #include <bits/stdc++.h>
// using namespace std;
// #define ll long long

class Solution
{
public:
    bool func(vector<int> &nums, int idx, vector<int> &dp)
    {
        if (idx >= nums.size())
            return 0;
        if (idx == nums.size() - 1)
            return true;
        if (dp[idx] != -1)
            return dp[idx];

        for (int i = 1; i <= nums[idx]; i++)
            if (func(nums, idx + i, dp))
                return dp[idx] = true;

        return dp[idx] = false;
    }

    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), -1);
        return func(nums, 0, dp);
    }
};