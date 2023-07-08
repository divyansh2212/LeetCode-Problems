class Solution {
    public int[] asteroidCollision(int[] arr) {
        
        int n = arr.length;
        Stack<Integer> st = new Stack<>();
        
        for(int i = 0; i < n; i++) 
        {
            if(st.size() == 0) {
                st.push(arr[i]);
            }
            else if(st.peek() > 0 && arr[i] > 0) {
                st.push(arr[i]);
            }
            else if(st.peek() < 0 && arr[i] < 0) {
                st.push(arr[i]);
            }
            
            else if(st.peek() > 0 && arr[i] < 0) 
            {
                while(st.size() != 0) {
                    if(st.peek() > Math.abs(arr[i]))
                        break;
                    else if(st.peek() == Math.abs(arr[i])) {
                        st.pop();
                        break;
                    }
                    else if(Math.abs(arr[i]) > st.peek()) {
                        st.pop();
                    }
                    
                    if(st.size() == 0 || st.peek() < 0) {
                        st.push(arr[i]);
                        break;
                    }
                }
            }
            
            else if(st.peek() < 0 && arr[i] > 0) 
            {
                st.push(arr[i]);
            }
        }
        
        n = st.size();
        int [] ans = new int[n];
        int k = 0;
        for(int x : st) {
            ans[k] = x;
            k++;
        }
        
        return ans;
    }
}