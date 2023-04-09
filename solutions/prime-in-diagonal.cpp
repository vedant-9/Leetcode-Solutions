class Solution {
public:
    bool is_prime(int n) {
        if(n == 1) return false;
        for(int i=2; i*i<=n; i++) {
            if(n%i == 0) return false;
        }
        return true;
    }
    int diagonalPrime(vector<vector<int>>& nums) {
        int sz = nums.size();
        int ans = 0;
        for(int i = 0; i < sz; i++) {
            if(is_prime(nums[i][i])) ans = max(ans, nums[i][i]);
            if(is_prime(nums[i][sz-i-1])) ans = max(ans, nums[i][sz-i-1]);
        }
        return ans;
    }
};
