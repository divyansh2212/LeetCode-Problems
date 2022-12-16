class MyQueue {
public:
    
    stack<int> st1, st2;
    
    MyQueue() {
        // st1.clear();
        // st2.clear();
    }
    
    void push(int x) {
        st1.push(x);
    }
    
    int pop() {
        int front = -1;
        while(!st1.empty())
        {
            int top = st1.top();
            st1.pop();
            st2.push(top);
        }
        
        if(st2.size())
        {
            front = st2.top();
            st2.pop();
        }
        
        while(!st2.empty())
        {
            int top = st2.top();
            st2.pop();
            st1.push(top);
        }
        
        return front;
    }
    
    int peek() {
        int front = -1;
        while(!st1.empty())
        {
            int top = st1.top();
            st1.pop();
            st2.push(top);
        }
        
        if(st2.size())
            front = st2.top();
        
        while(!st2.empty())
        {
            int top = st2.top();
            st2.pop();
            st1.push(top);
        }
        
        return front;
    }
    
    bool empty() {
        return (st1.size() + st2.size() == 0);
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */