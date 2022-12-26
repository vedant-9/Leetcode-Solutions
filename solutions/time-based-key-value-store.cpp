// https://leetcode.com/problems/time-based-key-value-store

class TimeMap {
public:
    map<string, vector<pair<int, string>>> mp;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        auto &v = mp[key];
        auto it = lower_bound(v.begin(), v.end(), make_pair(timestamp, ""), [](const auto &x, const auto &y)->bool{
            return x.first < y.first;
        });
        if(it == v.begin() and it->first > timestamp) return "";
        if(it == v.end() or it->first > timestamp) it--;
        return it->second;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */