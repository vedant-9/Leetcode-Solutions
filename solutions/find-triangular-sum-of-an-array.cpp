// https://leetcode.com/problems/find-triangular-sum-of-an-array

class Solution {
public:
    int triangularSum(vector<int>& a) {
        vector<int> cur;
        while(a.size()!=1) {
            for(int i=0;i<a.size()-1;i++) {
                cur.push_back((a[i]+a[i+1])%10);
            }   
            a=cur; cur.clear();
        }
        return a[0];
    }
};