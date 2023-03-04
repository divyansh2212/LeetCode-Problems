class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int n = nums.size();
        int i = 0, j = 0;
        int miniIdx = -1, maxIdx = -1;
        
        while(j < n)
        {
            if(nums[j] == minK)
                miniIdx = j;
            if(nums[j] == maxK)
                maxIdx = j;
            
            if(nums[j] < minK || nums[j] > maxK)
            {
                miniIdx = -1, maxIdx = -1;
                i = j + 1;
                j++;
            }
            
            else if(miniIdx == -1 || maxIdx == -1)
                j++;
            
            else
            {
                ans += min(miniIdx, maxIdx) - i + 1;
                j++;
            }
        }
        
        
        return ans;
    }
};