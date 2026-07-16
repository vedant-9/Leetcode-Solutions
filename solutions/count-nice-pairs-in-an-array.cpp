class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int n = nums.size();
        const int mod = 1e9 + 7;
        map<int, long long> mp;
        int ans = 0;
        for (auto x : nums) {
            int revx = 0, tmp = x;
            while (tmp) {
                revx = revx * 10 + tmp % 10;
                tmp /= 10;
            }
            if (mp.find(x - revx) == mp.end()) {
                ans = (ans + mp[x - revx]) % mod;
                mp[x - revx] = 1;
            } else {
                ans = (ans + mp[x - revx]) % mod;
                mp[x - revx]++;
            }
        }
        return ans;
    }
};
