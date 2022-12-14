class Solution {
    
    bool check(int mid, vector<int>& nums, int m)
    {
        int count = 1, curr = 0;
        
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] > mid)
                return false;
            if(curr + nums[i] <= mid)
                curr += nums[i];
            else
                curr = nums[i], count++;
        }
        
        return count <= m;
    }
    
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++)
            sum += nums[i];
        
        int lo = 0, hi = sum, mid, ans = sum;
        
        while(lo <= hi)
        {
            mid = lo + (hi - lo) / 2;
            if(check(mid, nums, m))
                hi = mid - 1, ans = mid;
            else
                lo = mid + 1;
        }
        
        return ans;
    }
};