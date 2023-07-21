class Solution {
    
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> dp(n, 1);
        
        int longest = 0;
        for(int i = 0; i < n; i++) {
            
            for(int j = 0; j < i; j++) {
                if(nums[i] > nums[j] && dp[i] < dp[j] + 1) {
                    dp[i] = dp[j] + 1;
                    length[i] = length[j];
                }
                else if(nums[i] > nums[j] && dp[i] == dp[j] + 1) {
                    length[i] += length[j];
                }
            }
            longest =  max(longest, dp[i]);
        }
        
        int ans = 0;
        
        for(int i = 0; i < n; i++) {
            if(dp[i] == longest) {
                ans += length[i];
            }
        }
        
        
        return ans;
    }
    
};