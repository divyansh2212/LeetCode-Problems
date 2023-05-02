class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        int product = 1;
        
        for(int i = 0; i < n; i++){
            if(nums[i] == 0)
                return 0;
            product *= nums[i] / abs(nums[i]);
        }
        
        return product;
    }
};