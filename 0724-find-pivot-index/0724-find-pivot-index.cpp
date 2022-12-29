class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int leftSum = 0;
        for(int i = 0; i < n; i++)
            leftSum += nums[i];
        
        int currSum = 0, ans = -1;
        for(int i = n - 1; i >= 0; i--)
        {
            currSum += nums[i];
            if(leftSum == currSum)
                ans = i;
            leftSum -= nums[i];
        }

        return ans;
    }
};