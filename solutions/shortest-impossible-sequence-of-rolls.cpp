// https://leetcode.com/problems/shortest-impossible-sequence-of-rolls

class Solution {
public:
    int shortestSequence(vector<int>& rolls, int k) {
        map<int,int> m;
        int c = 0, ans = 0;
        for(auto x:rolls) {
            m[x]++;
            if(m[x]==1) c++;
            if(c==k) {
                c=0;
                m.clear();
                ans++;
            }
        }
        return ans+1;
    }
};