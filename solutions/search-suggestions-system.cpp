// https://leetcode.com/problems/search-suggestions-system

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& a, string w) {
        sort(a.begin(),a.end());
        
        vector<vector<string>> res;
        
        auto it=a.begin();
        string cur="";
        
        for(auto ch:w) {
            cur+=ch;
            
            vector<string> tmp;
            it = lower_bound(it,a.end(),cur);
            
            for(int i=0;i<3 and it+i!=a.end();i++) {
                string s = *(it+i);
                if(s.find(cur)==string::npos) break;
                tmp.push_back(s);
            }
            res.push_back(tmp);
        }
        
        return res;
    }
};