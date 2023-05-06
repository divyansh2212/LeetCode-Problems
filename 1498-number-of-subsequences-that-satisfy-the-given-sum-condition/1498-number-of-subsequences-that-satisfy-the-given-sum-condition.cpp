class Solution {
    const int mod = 1e9 + 7;
    
    int binExp(int a, int b)
    {
        int ans = 1;
        while(b)
        {
            if(b & 1)
                ans = (ans * 1LL * a) % mod;
            a = (a * 1LL * a) % mod;
            b = (b >> 1);
        }
        return ans;
    }
    
    
public:
    int numSubseq(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for(int i = 0; i < n; i++)
        {
            int initial = ans;
            // for(int j = n - 1; j >= i; j--)
            // {
            //     if(nums[j] + nums[i] <= target)
            //     {
           
            //     }
            // }
            
            int idx = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin();
            idx--;
            if(idx < i || nums[i] + nums[idx] > target)
                break;
                     int len = (idx - i);
                    ans = (ans +0LL+ binExp(2, len)) % mod;
            
            if(ans == initial)
                break;
        }
        
        return ans;
    }
};