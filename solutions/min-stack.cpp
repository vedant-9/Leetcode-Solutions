// https://leetcode.com/problems/min-stack

class MinStack {
private:
    stack<int> main, minstack;
public:
    void push(int x) {
	    main.push(x);
	    if (minstack.empty() || x <= minstack.top()) minstack.push(x);	    
    }
    void pop() {
	    if (main.top() == minstack.top()) minstack.pop();
	    main.pop();
    }
    int top() {
	    return main.top();
    }
    int getMin() {
	    return minstack.top();
    }
};