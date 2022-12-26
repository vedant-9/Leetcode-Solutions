// https://leetcode.com/problems/check-if-every-row-and-column-contains-all-numbers

class Solution {
public:
    bool checkValid(vector<vector<int>>& a) {
        int n=a.size();
        for(int i=0;i<n;i++) {
            set<int> t1,t2;
            for(int j=0;j<n;j++) {
                t1.insert(a[i][j]);
                t2.insert(a[j][i]);
            }
            if(t1.size()!=n or t2.size()!=n) return false;
        }
        return true;
    }
};