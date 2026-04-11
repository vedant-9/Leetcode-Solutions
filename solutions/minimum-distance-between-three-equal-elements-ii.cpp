class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int, vector<int>> mp;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        int ans = 1e9;
        for (auto it : mp) {
            auto v = it.second;
            for (int i = 1; i < v.size() - 1; i++) {
                ans = min(ans, abs(v[i] - v[i - 1]) + abs(v[i] - v[i + 1]) +
                                   abs(v[i + 1] - v[i - 1]));
            }
        }
        if (ans == 1e9)
            return -1;
        return ans;
    }
};
