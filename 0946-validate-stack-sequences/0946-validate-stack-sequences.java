class Solution {
    public boolean validateStackSequences(int[] pushed, int[] popped) {
        
        int n = pushed.length;
        
        int i = 0; int j = 0;
        Stack<Integer> st = new Stack<Integer>();
        
        while(i < n)
        {
            
            while(st.size() > 0 && st.peek() == popped[j])
            {
                j++;
                st.pop();
            }
            
            st.push(pushed[i]);
            i++;
        }
        
        while(st.size() > 0 && j < n && st.peek() == popped[j])
        {
            st.pop();
            j++;
        }
        
        if(st.size() == 0)
            return true;
        return false;
    }
}