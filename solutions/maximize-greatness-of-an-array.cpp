class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0, j = 1, n = nums.size(), ans = 0;
        while(i < n) {
            while(j < n and nums[i] == nums[j]) j++;
            if(j >= n) break;
            ans++;
            i++;
            j++;
        }
        return ans;
    }
};
