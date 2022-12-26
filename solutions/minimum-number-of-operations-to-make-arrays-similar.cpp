// https://leetcode.com/problems/minimum-number-of-operations-to-make-arrays-similar

class Solution {
public:
    long long makeSimilar(vector<int>& a, vector<int>& b) {
        vector<int> ea, oa, eb, ob;
        for(auto &x: a) {
            if(x&1) oa.push_back(x);
            else ea.push_back(x);
        }
        for(auto &x: b) {
            if(x&1) ob.push_back(x);
            else eb.push_back(x);
        }
        
        sort(ea.begin(), ea.end());
        sort(oa.begin(), oa.end());
        sort(eb.begin(), eb.end());
        sort(ob.begin(), ob.end());
        
        long long ans = 0;
        for(int i=0; i<ea.size(); i++) {
            ans += abs(ea[i]-eb[i])/2;
        } 
        for(int i=0; i<oa.size(); i++) {
            ans += abs(oa[i]-ob[i])/2;
        }
        return ans/2;
    }
};