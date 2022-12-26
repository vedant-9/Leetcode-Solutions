// https://leetcode.com/problems/map-sum-pairs

class MapSum {
public:
    /** Initialize your data structure here. */
    map<string,int> m;
    MapSum() {
        
    }
    
    void insert(string key, int val) {
        m[key] = val;
    }
    
    int sum(string prefix) {
        int s = 0;
        int l = prefix.length();
        for(auto it:m)
        {
            int i = 0,f=0;
            for(i=0;i<l && i<it.first.length();i++)
            {
                if(it.first[i]!=prefix[i])
                {
                    f=1;
                    break;
                }
            }
            if(f==0 && l<=it.first.length())
            {
                s += it.second;
            }
        }
        return s;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */