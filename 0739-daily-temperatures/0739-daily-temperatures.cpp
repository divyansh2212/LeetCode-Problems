class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmp) {
        int n = tmp.size();
        vector<int> ans(n, 0);
        stack<int> st;
        st.push(n - 1);
        
        for(int i = n - 2; i >= 0; i--)
        {
            while(st.size() && tmp[st.top()] <= tmp[i])
                st.pop();
            if(st.size())
                ans[i] = st.top() - i;
            st.push(i);
        }
        return ans;
    }
};