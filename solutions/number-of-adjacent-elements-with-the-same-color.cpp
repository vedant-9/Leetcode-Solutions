class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> ans(n, 0), res;
        int cur = 0;
        for(auto q: queries) {
            if(q[0]-1 >= 0) {
                if(ans[q[0]] == ans[q[0]-1] and ans[q[0]]) cur--;
                if(q[1] == ans[q[0]-1] and q[1]) cur++; 
            }
            if(q[0]+1 < n) {
                if(ans[q[0]] == ans[q[0]+1] and ans[q[0]]) cur--;
                if(q[1] == ans[q[0]+1] and q[1]) cur++; 
            }
            ans[q[0]] = q[1];
            res.push_back(cur);
        }
        return res;
    }
};
