// https://leetcode.com/problems/two-out-of-three

class Solution {
public:
    void get(vector<int> &a) {
        sort(a.begin(),a.end());
        a.erase(unique(a.begin(),a.end()),a.end());
    }
    vector<int> twoOutOfThree(vector<int>& a, vector<int>& b, vector<int>& c) {
        get(a); get(b); get(c);
        map<int,int> m;
        for(auto x:a) m[x]++;
        for(auto x:b) m[x]++;
        for(auto x:c) m[x]++;
        vector<int> res;
        for(auto it:m) {
            if(it.second>=2)
                res.push_back(it.first);
        }
        return res;
    }
};