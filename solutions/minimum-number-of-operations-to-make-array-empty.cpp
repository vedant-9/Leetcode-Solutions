class Solution {
public:
    int minOperations(vector<int>& nums) {
        map<int, int> cnt;
        for(auto x: nums) {
            cnt[x]++;
        }
        int ans = 0;
        for(auto it: cnt) {
            if(it.second == 1) return -1;
            if(it.second % 3 == 0) ans += it.second/3;
            else ans += it.second/3+1;
        }
        return ans;
    }
};
