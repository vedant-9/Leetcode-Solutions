class Solution {
public:
    const int mod = 1e9+7;
    int sumDistance(vector<int>& nums, string s, int d) {
        int n = nums.size();
        for(int i = 0; i < n; i++){
            if(s[i] == 'R') nums[i] += d;
            else nums[i] -= d;
        }
        long long ans = 0, pref = 0;
        sort(nums.begin(), nums.end());
        for(long long i = 0; i < n; i++){
            ans += i * (long long) nums[i] - pref;
            ans %= mod;
            pref += nums[i];
        }
        return ans;
    }
};
