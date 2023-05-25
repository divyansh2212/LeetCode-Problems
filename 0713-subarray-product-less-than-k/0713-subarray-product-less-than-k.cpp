class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;
        
        int i = 0, j = 0;
        int product = 1;
        
        while(j < n)
        {
            product *= nums[j];
            if(product < k)
            {
                ans += (j - i + 1);
                j++;
            }
            else
            {
                while(product >= k && i <= j)
                {
                    product /= nums[i];
                    i++;
                }
                if(product < k)
                    ans += (j - i + 1);
                
                j++;
            }
        }
        
        return ans;
    }
    
};