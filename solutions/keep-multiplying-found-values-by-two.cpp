// https://leetcode.com/problems/keep-multiplying-found-values-by-two

class Solution {
public:
    int findFinalValue(vector<int>& a, int o) {
        map<int,int> m;
        for(auto x:a) m[x]++;
        while(m.find(o)!=m.end()) {
            m[o]--;
            if(m[o]==0) m.erase(o);
            o*=2;
        }
        return o;
    }
};