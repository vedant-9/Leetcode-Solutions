class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int xo = 0;
        for(auto x: nums) {
            xo ^= x;
        }
        if(xo) return nums.size();

        int zc = 0;
        for(auto x: nums) {
            if(x == 0) zc++;
        }
        
        if(zc == nums.size()) return 0;
        return nums.size() - 1;
    }
};
