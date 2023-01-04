class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        
        for(int i = 0; i < n; i++)
        {
            for(int j = 2; j * j <= nums[i]; j++)
            {
                if(nums[i] % j == 0)
                {
                    st.insert(j);
                    while(nums[i] % j == 0)
                        nums[i] /= j;
                }
            }
            if(nums[i] > 1)
                st.insert(nums[i]);
        }
        
        return st.size();
    }
};