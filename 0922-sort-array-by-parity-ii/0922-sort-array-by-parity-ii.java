class Solution {
    public int[] sortArrayByParityII(int[] nums) {
        
        int n = nums.length;
        int arr[] = new int[n];
        
        int idx = 0;
        // we are filling even elements
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 0)
            {
                arr[idx] = nums[i];
                idx += 2;
            }
        }
        
        // we are filling odd elements
        idx = 1;
        for(int i = 0; i < n; i++)
        {
            if(nums[i] % 2 == 1)
            {
                arr[idx] = nums[i];
                idx += 2;
            }
        }
        
        return arr;
    }
}