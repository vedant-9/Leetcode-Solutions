// https://leetcode.com/problems/divide-array-into-equal-pairs

class Solution {
public:
    bool divideArray(vector<int>& a) {
        sort(a.begin(),a.end());
        for(int i=0;i<a.size();i+=2) {
            if(a[i]!=a[i+1]) {
                return 0;
            }
        }
        return 1;
    }
};