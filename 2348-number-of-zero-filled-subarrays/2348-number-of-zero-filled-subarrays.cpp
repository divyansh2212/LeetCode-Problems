class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        
        int i = 0, j = 0;
        
        while(j < n)
        {
            if(nums[j] != 0)
            {
                long long len = j - i;
                ans += (len * (len + 1)) / 2;
                
                j++;
                i = j;
            }
            else
                j++;
        }
        long long len = j - i;
        ans += (len * (len + 1)) / 2;
        
        return ans;
    }
};