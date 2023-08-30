class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int last = nums[n - 1];
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] <= last) {
                last = nums[i];
            }
            else {
                int factors = nums[i] / last;
                if(nums[i] % last) {
                    factors++;
                }
                last = min(last, nums[i] / factors);
                ans += (factors - 1);
            }
        }
        
        return ans;
    }
};