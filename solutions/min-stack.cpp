class MinStack {
public:
    stack<int> mainStack, minStack;
    MinStack() {
        
    }
    
    void push(int value) {
        mainStack.push(value);
        if(minStack.empty() or value <= minStack.top()) minStack.push(value);
    }
    
    void pop() {
        if(mainStack.top() == minStack.top()) minStack.pop();
        mainStack.pop();
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
