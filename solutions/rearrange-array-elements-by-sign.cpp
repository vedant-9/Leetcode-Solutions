// https://leetcode.com/problems/rearrange-array-elements-by-sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& a) {
        vector<int> pos,neg,ans;
        for(auto x:a) {
            if(x>0) pos.push_back(x);
            else neg.push_back(x);
        }
        int i=0;
        while(i<a.size()/2) {
            ans.push_back(pos[i]);
            ans.push_back(neg[i]);
            i++;
        }
        return ans;
    }
};