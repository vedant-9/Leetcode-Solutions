// https://leetcode.com/problems/my-calendar-iii

class MyCalendarThree {
public:
    map<int, int> mp;
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        mp[start]++; mp[end]--;
        int k = 0, cur = 0;
        for(auto &t: mp) {
            cur += t.second;
            k = max(k, cur);
        }
        return k;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */