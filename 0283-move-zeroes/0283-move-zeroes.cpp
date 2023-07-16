class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        
        for(int i = 1; i < n; i++) {
            int idx = i;
            while(idx >= 1 && nums[idx - 1] == 0 && nums[idx] != 0) {
                swap(nums[idx], nums[idx - 1]);
                idx--;
            }
        }
        
    }
};