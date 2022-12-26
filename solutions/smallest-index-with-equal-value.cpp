// https://leetcode.com/problems/smallest-index-with-equal-value

class Solution {
public:
    int smallestEqual(vector<int>& a) {
        int n=a.size(),idx=-1;
        for(int i=0;i<n;i++) {
            if(i%10==a[i]) {
                idx=i;
                break;
            }
        }
        return idx;
    }
};