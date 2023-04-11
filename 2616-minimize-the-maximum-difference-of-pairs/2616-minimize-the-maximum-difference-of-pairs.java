class Solution {
    
    Boolean check(int [] nums, int p, int maxm)
    {
        int n = nums.length;
        int curr = 0;
        
        for(int i = 1; i < n;)
        {
            if(curr == p)
                return true;
            if(nums[i] - nums[i - 1] <= maxm)
            {
                curr++;
                i += 2;
            }
            else
                i++;
        }
        
        return (curr >= p);
    }
    
    public int minimizeMax(int[] nums, int p) {
        int n = nums.length;
        Arrays.sort(nums);
        
        int lo = 0, hi = (int)1e9, ans = (int)1e9;
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            // System.out.println(mid);
            if(check(nums, p, mid))
            {
                hi = mid - 1;
                ans = mid;
            }
            else
                lo = mid + 1;
        }
        
        return ans;
    }
}