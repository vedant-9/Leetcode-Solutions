class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        map<int, int> col;
        map<int, int> cnt;
        
        vector<int> res;
        for(auto q: queries) {
            if(col.find(q[0]) != col.end()) {
                int prev = col[q[0]];
                col[q[0]] = q[1];
                cnt[q[1]]++;
                cnt[prev]--;
                if(cnt[prev] == 0) cnt.erase(prev);
            } else {
                col[q[0]] = q[1];
                cnt[q[1]]++;
            }
            res.push_back(cnt.size());
        }
        
        return res;
    }
};
