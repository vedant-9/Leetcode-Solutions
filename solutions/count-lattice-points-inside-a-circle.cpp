// https://leetcode.com/problems/count-lattice-points-inside-a-circle

class Solution {
public:
    int countLatticePoints(vector<vector<int>>& a) {
        int cnt=0;
        for(int i=0;i<=200;i++) {
            for(int j=0;j<=200;j++) {
                for(auto &v:a) {
                    if((i-v[0])*(i-v[0])+(j-v[1])*(j-v[1])<=v[2]*v[2]) {
                        cnt++; break;
                    }
                }
            }
        }
        return cnt;
    }
};