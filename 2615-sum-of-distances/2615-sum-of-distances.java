class Solution {
    public long[] distance(int[] nums) {
        
        int n = nums.length;
        
        long[] ans = new long[n];
        HashMap<Integer, Long> left = new HashMap<Integer, Long>();
        HashMap<Integer, Long> total = new HashMap<Integer, Long>();
        HashMap<Integer, Integer> leftCount = new HashMap<Integer, Integer>();
        HashMap<Integer, Integer> totalCount = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < n; i++)
        {
            totalCount.put(nums[i], totalCount.getOrDefault(nums[i], 0) + 1);
            total.put(nums[i], total.getOrDefault(nums[i], 0L) + i);
        }
        
        for(int i = 0; i < n; i++)
        {
            leftCount.put(nums[i], leftCount.getOrDefault(nums[i], 0) + 1);
            left.put(nums[i], left.getOrDefault(nums[i], 0L) + i);
            
            long leftVals = left.get(nums[i]) - i;
            long leftFreq = leftCount.get(nums[i]) - 1;
            long rightVals = total.get(nums[i]) - left.get(nums[i]);
            long rightFreq = totalCount.get(nums[i]) - leftCount.get(nums[i]);
            
            ans[i] = (leftFreq * i) - leftVals + rightVals - (rightFreq * i);
            
        }
        
        return ans;
    }
}
