// https://leetcode.com/problems/find-target-indices-after-sorting-array

class Solution {
public:
    vector<int> targetIndices(vector<int>& a, int tar) {
        sort(a.begin(),a.end());
        vector<int> ans;
        for(int i=0;i<a.size();i++) {
            if(a[i]==tar) ans.push_back(i);
        }
        return ans;
    }
};