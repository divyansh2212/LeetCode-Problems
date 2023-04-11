class Solution {
    public int[] rearrangeArray(int[] nums) {
        
        int n = nums.length;
        
        List<Integer> positive = new ArrayList<>();
        List<Integer> negative = new ArrayList<>();
        
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < 0)
                negative.add(nums[i]);
            else
                positive.add(nums[i]);
        }
        
        int i = 0, j = 0;
        
        while(i < positive.size())
        {
            nums[j] = positive.get(i);
            nums[j + 1] = negative.get(i);
            i++; j += 2;
        }
        
        return nums;
        
    }
}