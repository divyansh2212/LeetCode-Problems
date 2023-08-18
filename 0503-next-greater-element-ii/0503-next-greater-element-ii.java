class Solution {
    public int[] nextGreaterElements(int[] nums) 
    {
        int n = nums.length;
        
        Stack<Integer> st = new Stack<>();
        int [] ans = new int[n];
        ArrayList<Integer> arr = new ArrayList<>();
        for(int i = 0; i < n; i++) {
            arr.add(nums[i]);
        }
        for(int i = 0; i < n; i++) {
            arr.add(nums[i]);
        }
        
        for(int i = (2*n) - 1; i >= 0; i--)
        {
            while(st.size() > 0 && st.peek() <= arr.get(i)) {
                st.pop();
            }
            
            if(i < n)
            {
                if(st.size() == 0) {
                    ans[i] = -1;
                }
                else
                    ans[i] = st.peek();
            }
            
            st.push(arr.get(i));
        }
        
        return ans;
    }
}