class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        vector<int> cnt(n, 0);
        for(auto x: nums) {
            int rem = (x%value + value)%value;
            if(rem < n) cnt[rem]++;
        }
        for(int i=0; i<n; i++) {
            if(!cnt[i%value]) {
                return i;
            }
            cnt[i%value]--;
        }
        return n;
    }
};
