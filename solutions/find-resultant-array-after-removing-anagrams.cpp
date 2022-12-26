// https://leetcode.com/problems/find-resultant-array-after-removing-anagrams

class Solution {
public:
    vector<string> removeAnagrams(vector<string>& a) {
        set<string> s;
        vector<string> res;
        string prev="";
        for(auto &x:a) {
            string y = x;
            sort(y.begin(),y.end());
            if(prev!=y) {
                res.push_back(x);
                s.insert(y);
            }
            prev=y;
        }
        return res;
    }
};