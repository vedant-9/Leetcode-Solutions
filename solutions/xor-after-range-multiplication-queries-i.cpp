class Solution {
public:
    const int mod = 1e9 + 7;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        for (auto q : queries) {
            for (int i = q[0]; i <= q[1]; i += q[2]) {
                nums[i] = ((long long)nums[i] * q[3]) % mod;
            }
        }
        int ans = 0;
        for (auto x : nums) {
            ans ^= x;
        }
        return ans;
    }
};
