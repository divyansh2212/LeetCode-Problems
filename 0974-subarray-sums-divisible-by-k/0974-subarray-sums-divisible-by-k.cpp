class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        int ans = 0;
        vector<int> prevRecord(k, 0);
        // prevRecord[0]++;
        int n = nums.size(), currSum = 0;
        
        for(int i = 0; i < n; i++)
        {
            currSum = (currSum + ((nums[i] % k) + k)) % k;
            if(currSum == 0)
                ans++;
            ans += prevRecord[currSum];
            prevRecord[currSum]++;
        }
        
        return ans;
    }
};