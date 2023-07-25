class MinStack {
    
    stack<pair<int, int>> st;
    
public:
    MinStack() {
        // st.clear();
    }
    
    void push(int val) {
        if(st.size() == 0) {
            st.push({val, val});
        }
        else {
            int mini = st.top().second;
            st.push({val, min(mini, val)});
        }
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */