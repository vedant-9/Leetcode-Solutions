// https://leetcode.com/problems/bitwise-xor-of-all-pairings

class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        auto getXor = [](vector<int> &v)->int{
            int xo = 0;
            for(auto &x: v) xo ^= x;
            return xo;
        };
        if(n%2 == 0 and m%2 == 0) return 0;
        else if(n%2 == 0) return getXor(nums1);
        else if(m%2 == 0) return getXor(nums2);
        return (getXor(nums1)^getXor(nums2));
    }
};