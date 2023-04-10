class Solution {
public:
    bool isValid(string s) {
        
        int n = s.length();
        stack<char> st;
        
        st.push(s[0]);
        
        for(int i = 1; i < n; i++)
        {
            if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                st.push(s[i]);
            else if(s[i] == '}')
            {
                if(st.size() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
            else if(s[i] == ']')
            {
                if(st.size() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            else if(s[i] == ')')
            {
                if(st.size() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
        }
        
        if(st.size())
            return false;
        return true;
    }
};