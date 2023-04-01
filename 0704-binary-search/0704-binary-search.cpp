class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size() - 1, lo = 0, mid;
            
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            
            if(nums[mid] == target)
                return mid;
            if(nums[mid] > target)
                hi = mid - 1;
            else lo = mid + 1;
        }
        return -1;
    }
};