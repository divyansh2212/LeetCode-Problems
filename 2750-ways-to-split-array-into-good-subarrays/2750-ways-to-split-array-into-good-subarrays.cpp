class Solution {
    
    const int mod = 1e9 + 7;
    
public:
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        
        int n = nums.size();
        int ans = 1;
        
        int firstidx = -1, lastidx = -2;
        for(int i = 0; i < n; i++) {
            if(nums[i] == 1) {
                if(firstidx == -1)
                    firstidx = i;
                lastidx = i;
            }
        }
        
        int i = firstidx;
        int curr = 0;
        while(i <= lastidx)
        {
            int curr = 1;
            i++;
            while(i <= lastidx && nums[i] != 1) {
                i++;
                curr++;
            }
            ans = (ans * 1LL * curr) % mod;
        }
        
        if(firstidx == -1)
            return 0;
        
        return ans;
    }
};