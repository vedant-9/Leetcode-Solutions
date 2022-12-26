// https://leetcode.com/problems/minimum-cost-homecoming-of-a-robot-in-a-grid

class Solution {
public:
    int minCost(vector<int>& sp, vector<int>& hp, vector<int>& r, vector<int>& c) {
        int m=r.size(),n=c.size(),res=0;
        int i=sp[0],j=sp[1];
        while(i!=hp[0]) {
            i+=(hp[0]-i)/abs(hp[0]-i);
            res+=r[i];
        }
        while(j!=hp[1]) {
            j+=(hp[1]-j)/abs(hp[1]-j);
            res+=c[j];
        }
        return res;
    }
};