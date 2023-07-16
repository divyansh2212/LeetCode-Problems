class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        
        int start = 0, end = n - 1;
        
        vector<int> result(n);
        int idx = n - 1;
        while(start <= end) {
            if(nums[start] >= nums[end]) {
                result[idx] = nums[start];
                start++;
            }
            else {
                result[idx] = nums[end];
                end--;
            }
            idx--;
        }
        
        return result;
    }
};