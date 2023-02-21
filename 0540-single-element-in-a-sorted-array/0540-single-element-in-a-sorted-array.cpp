class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        
//         int xr = 0;
//         for(int i = 0; i < n; i++)
//             xr = xr ^ nums[i];
        
//         return xr;
        
        int lo = 0, hi = n - 1, ans = -1;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            
            if(mid == 0 && (mid + 1 == n || nums[mid] != nums[mid + 1]))
                    return nums[mid];
            if(mid == n - 1 && (nums[mid] != nums[mid - 1]))
                    return nums[mid];
            if(mid - 1 >= 0 && mid + 1 < n && nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];
            
            if(nums[mid] == nums[mid - 1])
            {
                if((mid + 1) % 2)
                    hi = mid - 1;
                else
                    lo = mid + 1;
            }
            
            else if(nums[mid] == nums[mid + 1])
            {
                if((mid + 1) % 2)
                    lo = mid + 1;
                else
                    hi = mid - 1;
            }
        }
        
        return ans;
    }
};