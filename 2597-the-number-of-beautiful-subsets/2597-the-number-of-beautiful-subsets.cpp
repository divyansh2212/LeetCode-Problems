class Solution {
    
    int solve(int idx, vector<int> &nums, int  &k, vector<int> &hashMap)
    {
        if(idx == nums.size())
            return 1;
        
        int way1 = solve(idx + 1, nums, k, hashMap);
        int way2 = 0;
        
        if(nums[idx] - k < 0 || hashMap[nums[idx] - k] == 0)
        {
            hashMap[nums[idx]]++;
            way2 = solve(idx + 1, nums, k, hashMap);
            hashMap[nums[idx]]--;
        }
        
        return way1 + way2;
    }
    
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<int> hashMap(1002, 0);
        
        return solve(0, nums, k, hashMap) - 1;
    }
};