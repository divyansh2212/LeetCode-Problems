class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        int closest = INT_MAX;
        int ans = -1;
        int n = nums.size();
        for(int i = 0; i < n; i++)
        {
            int diff = abs(nums[i]);
            if(diff < closest)
            {
                closest = diff;
                ans = nums[i];
            }
            else if(diff == closest)
                ans = max(ans, nums[i]);
        }
        return ans;
    }
};