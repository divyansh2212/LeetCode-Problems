class MyStack {
public:
    deque<int> dq;
    MyStack() {
        
    }
    
    void push(int x) {
        dq.push_back(x);
    }
    
    int pop() {
        int top = dq.back();
        dq.pop_back();
        return top;
    }
    
    int top() {
        int top = dq.back();
        return top;
    }
    
    bool empty() {
        return dq.size() == 0;
    }
};