class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size(), ans = 0;

        sort(nums.begin(), nums.end());

        map<int, int> mp;
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int product = nums[i] * nums[j];
                ans += 8 * mp[product];
                mp[product]++;
            }
        }

        return ans;
    }
};
