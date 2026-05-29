class Solution {
public:
    int minElement(vector<int>& nums) {
        int result = INT_MAX;
        for (int n : nums) {
            int sum = 0;
            while (n > 0) {
                sum += n % 10;
                n /= 10;
            }
            result = min(result, sum);
        }
        return result;
    }
};
