class MinStack {
    stack<int> m,helper;
public:
    /** initialize your data structure here. */
    MinStack() {
        helper.push(INT_MAX);
    }
    
    void push(int x) {
        m.push(x);
         if(x<=helper.top()){
            helper.push(x);
        }
    }
    
    void pop() {
        int x = m.top();
        if(x == helper.top())
        {
            helper.pop();
        }
        m.pop();
    }
    
    int top() {
        return m.top();
    }
    
    int getMin() {
        return helper.top();
    }

};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */