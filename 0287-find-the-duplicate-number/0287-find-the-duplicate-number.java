class Solution {
    public int findDuplicate(int[] nums) {
        int n = nums.length;
        
        int slow = nums[0], fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(fast != slow);
        
        fast = nums[0];
        
        while(fast != slow)
        {
            slow = nums[slow];
            fast = nums[fast];
        }
        
        return slow;
    }
}