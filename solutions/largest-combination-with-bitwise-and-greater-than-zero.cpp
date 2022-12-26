// https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero

class Solution {
public:
    int largestCombination(vector<int>& a) {
        int cnt[32]={0};
        for(auto x:a) {
            bitset<32> b(x);
            for(int j=0;j<32;j++) cnt[j]+=b[j];
        }
        int mx = 0;
        for(int j=0;j<32;j++) {
            mx = max(mx,cnt[j]);
        }
        return mx;
    }
};