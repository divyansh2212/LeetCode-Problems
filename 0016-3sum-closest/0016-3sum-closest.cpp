class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int minmDiff = INT_MAX, ans = -1;
        for(int i = 0; i < n - 2; i++)
        {
            int j = i + 1, k = n - 1;
            while(j < k)
            {
                if(nums[i] + nums[j] + nums[k] == target)
                    return target;
                else if(nums[i] + nums[j] + nums[k] > target)
                {
                    if(nums[i] + nums[j] + nums[k] - target < minmDiff)
                    {
                        minmDiff = nums[i] + nums[j] + nums[k] - target;
                        ans = nums[i] + nums[j] + nums[k];
                    }
                    k--;
                }
                else
                {
                    if(target - nums[i] - nums[j] - nums[k] < minmDiff)
                    {
                        minmDiff = target - nums[i] - nums[j] - nums[k];
                        ans = nums[i] + nums[j] + nums[k];
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};