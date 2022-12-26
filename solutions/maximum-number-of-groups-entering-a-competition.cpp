// https://leetcode.com/problems/maximum-number-of-groups-entering-a-competition

class Solution {
public:
    int maximumGroups(vector<int>& a) {
        int n = a.size();
        // k*(k+1)/2 <= n 
        int k = sqrt(2*n);
        if(k*(k+1)>2*n) k--;
        return k;
    }
};