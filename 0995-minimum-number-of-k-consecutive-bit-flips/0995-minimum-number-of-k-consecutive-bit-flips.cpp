class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        
        int n = nums.size();
        vector<int> flips(n + 1, 0);
        
        int ans = 0;
        for(int i = 0; i < n; i++) {
            
            if(i)
                flips[i] += flips[i - 1];
            
            if((flips[i] % 2 && nums[i]) || (flips[i] % 2 == 0 && nums[i] == 0)) {
                ans++;
                flips[i]++;
                if(i + k > n)
                    return -1;
                flips[i + k]--;
            }
        }
        
        return ans;
    }
};