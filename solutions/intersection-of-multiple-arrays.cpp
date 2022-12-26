// https://leetcode.com/problems/intersection-of-multiple-arrays

class Solution {
public:
    vector<int> intersection(vector<vector<int>>& a) {
        int n = a.size();
        vector<int> ans;
        for(int i=0;i<a[0].size();i++) {
            int f=0;
            for(int j=1;j<n;j++) {
                for(int k=0;k<a[j].size();k++) {
                    if(a[0][i]==a[j][k]) {
                        f++;
                        break;
                    }
                }
            }
            if(f==n-1) {
                ans.push_back(a[0][i]);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};