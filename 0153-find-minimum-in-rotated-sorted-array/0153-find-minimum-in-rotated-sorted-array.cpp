class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans = INT_MAX, n = nums.size();
        
        int lo = 0, hi = n - 1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            ans = min(ans, nums[mid]);
            ans = min(ans, nums[lo]);
            ans = min(ans, nums[hi]);
            
            if(nums[hi] <= nums[mid])
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        
        return ans;
    }
};