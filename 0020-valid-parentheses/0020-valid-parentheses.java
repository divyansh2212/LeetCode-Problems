class Solution {
    public boolean isValid(String str) {
        
        Stack<Character> st = new Stack<>();
        int n = str.length();
        
        for(int i = 0; i < n; i++)
        {
            char ch = str.charAt(i);
            
            // open brackets
            if(ch == '(') {
                st.push(ch);    
            }
            else if(ch == '[') {
                st.push(ch);  
            }
            else if(ch == '{') {
                st.push(ch);  
            }
            
            else if(ch == ')') {
                
                if(st.size() == 0)
                    return false;
                else if(st.peek() == '(')
                    st.pop();
                else {
                    return false;
                }
            }
            
            else if(ch == ']') {
                
                if(st.size() == 0)
                    return false;
                else if(st.peek() == '[')
                    st.pop();
                else {
                    return false;
                }
            }
            
            else if(ch == '}') {
                if(st.size() == 0)
                    return false;
                else if(st.peek() == '{')
                    st.pop();
                else {
                    return false;
                }
            }
        }
        
        return (st.size() == 0);
    }
}