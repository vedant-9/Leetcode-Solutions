// https://leetcode.com/problems/maximum-xor-after-operations

class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int orz=0;
        for(auto x:nums) orz|=x;
        return orz;
    }
};