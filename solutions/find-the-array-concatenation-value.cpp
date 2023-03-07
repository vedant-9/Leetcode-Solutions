class Solution {
public:
    long long findTheArrayConcVal(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        for(int i=0; i<n/2; i++) {
            ans += stoll(to_string(nums[i])+to_string(nums[n-i-1]));
        }
        if(n&1) ans += nums[n/2];
        return ans;
    }
};
