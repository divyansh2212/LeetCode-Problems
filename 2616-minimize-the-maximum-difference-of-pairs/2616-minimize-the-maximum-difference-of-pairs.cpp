class Solution {
    
    bool check(vector<int>& nums, int p, int diff)
    {
        int n = nums.size();
        int curr = 0;
        for(int i = 0; i < n - 1;)
        {
            if(nums[i + 1] - nums[i] <= diff) {
                i += 2, curr++;
            }
            else
                i++;
        }
        return (curr >= p);
    }
    
public:
    int minimizeMax(vector<int>& nums, int p) {
        if(p == 0) return 0;
        int n = nums.size();
        int lo = 0, hi = 1e9, ans = 1e9;
        sort(nums.begin(), nums.end());
        
        while(lo <= hi)
        {
            int mid = lo + (hi - lo) / 2;
            if(check(nums, p, mid)) {
                ans = mid;
                hi = mid - 1;
            }
            else {
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};