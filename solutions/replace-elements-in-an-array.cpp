// https://leetcode.com/problems/replace-elements-in-an-array

class Solution {
public:
    vector<int> arrayChange(vector<int>& a, vector<vector<int>>& ops) {
        map<int,int> ind;
        int n = a.size(), m = ops.size();
        for(int i=0;i<n;i++) 
            ind[a[i]]=i;
        for(int k=0;k<m;k++) {
            int j = ind[ops[k][0]];
            a[j] = ops[k][1];
            ind[a[j]]=j;
        }
        return a;
    }
};