class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        // sort(nums.begin(), nums.end());
        
        map<int, int> mp;
        for(int i = 0; i < n; i++)
        {
            if(mp.find(target - nums[i]) != mp.end())
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};