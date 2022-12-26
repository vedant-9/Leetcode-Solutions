// https://leetcode.com/problems/find-the-difference-of-two-arrays

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& a, vector<int>& b) {
        vector<vector<int>> ans;
        vector<int> t;
        sort(a.begin(),a.end()); sort(b.begin(),b.end());
        a.erase(unique(a.begin(),a.end()),a.end());
        b.erase(unique(b.begin(),b.end()),b.end());
        for(auto x:a) {
            int f=0;
            for(auto y:b) {
                if(x==y) {
                    f=1; break;
                }
            }
            if(f==0) t.push_back(x);
        }
        ans.push_back(t);
        t.clear();
        for(auto x:b) {
            int f=0;
            for(auto y:a) {
                if(x==y) {
                    f=1; break;
                }
            }
            if(f==0) t.push_back(x);
        }
        ans.push_back(t);
        return ans;
    }
};