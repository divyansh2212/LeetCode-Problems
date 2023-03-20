class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        vector<int> freq(100001, 0);
        int n = nums.size();
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] >= 0)
                freq[nums[i] % value]++;
            else
            {
                int absVal = abs(nums[i]) % value;
                if(absVal == 0)
                    freq[0]++;
                else
                    freq[value - absVal]++;
            }
        }
            
        
        for(int i = 0; i <= n; i++)
        {
            if(freq[i % value] > 0)
            {
                freq[i % value]--;
            }
            else
                return i;
        }
        
        return n;
    }
};