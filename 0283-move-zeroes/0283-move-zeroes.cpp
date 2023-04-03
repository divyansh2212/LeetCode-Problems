class Solution {
public:
    void moveZeroes(vector<int>& nums) {
       
        int n = nums.size();
        
        int zeros = 0;
        for(int i = 0; i < n; i++)
            if(nums[i] == 0)
                zeros++;
        
        int j = 0;
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] != 0)
            {
                nums[j] = nums[i];
                j++;
            }
        }
        
        j = n - 1;
        
        while(zeros--)
            nums[j] = 0, j--;
    }
};