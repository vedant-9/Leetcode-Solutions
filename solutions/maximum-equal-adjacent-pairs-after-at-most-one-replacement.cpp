class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<string, int> mp;
        int res = 0, ans = 0;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) res++;
            else {
                int x = nums[i], y = nums[i+1];
                if(x > y) swap(x, y);
                string key = to_string(x) + "," + to_string(y);
                mp[key]++;
                ans = max(ans, mp[key]);
            }
        }
        return res + ans;
    }
};
