
class Solution
{

    bool check(vector<int> &nums, int mid)
    {
        int n = nums.size();
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            if (sum > (i + 1) * 1LL * mid)
                return false;
        }
        return true;
    }

public:
    int minimizeArrayValue(vector<int> &nums)
    {
        int n = nums.size(), mx = INT_MIN;
        for (int i = 0; i < n; i++)
            mx = max(mx, nums[i]);

        int lo = 0, hi = mx, ans = mx, mid;

        while (lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if (check(nums, mid))
                ans = mid, hi = mid - 1;
            else
                lo = mid + 1;
        }
        return ans;
    }
};