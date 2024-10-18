class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int max_or = 0;
        for(auto x: nums) {
            max_or |= x;
        }
        int n = nums.size(), cnt = 0;
        for(int i = 1; i < (1<<n); i++) {
            int cur_or = 0;
            for(int j = 0; j < n; j++) {
                if(i & (1<<j)) {
                    cur_or |= nums[j];
                }
            }
            if(cur_or == max_or) cnt++;
        }
        return cnt;
    }
};
