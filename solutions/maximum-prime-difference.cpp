class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        auto isPrime = [](int n) {
            if (n < 2) return false;
            for (int i = 2; i * i <= n; i++)
                if (n % i == 0) return false;
            return true;
        };
        int first = -1, last = -1;
        for (int i = 0; i < nums.size(); i++) {
            if (isPrime(nums[i])) {
                if (first == -1) first = i;
                last = i;
            }
        }
        return last - first;
    }
};
