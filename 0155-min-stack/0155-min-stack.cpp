class MinStack {
    vector<int> elements;
    multiset<int> st;
public:
    MinStack() {
        elements.clear();
        st.clear();
    }
    
    void push(int val) {
        st.insert(val);
        elements.push_back(val);
    }
    
    void pop() {
        int val = elements.back();
        auto it = st.find(val);
        st.erase(it);
        elements.pop_back();
    }
    
    int top() {
        return elements.back();
    }
    
    int getMin() {
        return *st.begin();
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