// https://leetcode.com/problems/count-integers-in-intervals

typedef pair<int,int> pii;
class CountIntervals {
public:
    set<pair<int,int>> s;
    int cnt=0;
    CountIntervals() {
        
    }
    
    void add(int left, int right) {
        auto it = s.lower_bound({left,left});
        if (it != s.begin())
            it--;
        vector<pair<int, int>> to_erase;
        int l = left, r = right;
        while (it != s.end() && it->first <= right) {
            if (it->second < left - 1) {
                it++;
                continue;
            }
            
            l = min(l, it->first);
            r = max(it->second, right);
            to_erase.push_back(*it);
            it++;
        }
        
        for (auto &p : to_erase) {
            cnt -= p.second - p.first + 1;
            s.erase(p);
        }
        
        s.emplace(l, r);
        cnt += r - l + 1;
    }
    
    int count() {
        return cnt;
    }
};

/**
 * Your CountIntervals object will be instantiated and called as such:
 * CountIntervals* obj = new CountIntervals();
 * obj->add(left,right);
 * int param_2 = obj->count();
 */