class BrowserHistory {
public:
    deque<string> a;
    int cur;
    BrowserHistory(string homepage) {
        cur = 1;
        a.push_back(homepage);
    }
    
    void visit(string url) {
        int tsz = a.size();
        while(tsz > cur) {
            a.pop_back();
            tsz--;
        }
        cur++;
        a.push_back(url);
    }
    
    string back(int steps) {
        cur = max(cur-steps, 1);
        return a[cur-1];
    }
    
    string forward(int steps) {
        cur = min((int)a.size(), cur+steps);
        return a[cur-1];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
