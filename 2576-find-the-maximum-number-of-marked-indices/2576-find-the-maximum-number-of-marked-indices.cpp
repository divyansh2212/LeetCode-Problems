class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int idx = 0;
        for(int i = (n + 1) / 2; i < n; i++)
            if(nums[idx] * 2 <= nums[i])
                idx++;
        
        return 2 * idx;
    }
};