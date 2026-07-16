class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre_max(n), pre_gcd(n);
        pre_max[0] = nums[0];
        pre_gcd[0] = nums[0];
        for(int i = 1; i < n; i++) {
            pre_max[i] = max(pre_max[i-1], nums[i]);
            pre_gcd[i] = __gcd(pre_max[i], nums[i]);
        }
        sort(pre_gcd.begin(), pre_gcd.end());
        long long sum = 0;
        for(int i = 0; i < n/2; i++) {
            sum += __gcd(pre_gcd[i], pre_gcd[n-i-1]);
        }
        return sum;
    }
};
