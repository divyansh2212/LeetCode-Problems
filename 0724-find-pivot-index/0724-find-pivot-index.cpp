class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i - 1] + nums[i];
        
        int currSum = 0, ans = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            currSum += nums[i];
            if(prefix[i] == currSum)
                ans = i;
        }
            
        
        return ans;
    }
};