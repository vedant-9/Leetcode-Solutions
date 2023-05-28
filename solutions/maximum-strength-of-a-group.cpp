class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        long long maxNegIdx = -1, ans = 1, res = 1;
        int negCnt = 0, n = nums.size();
        for(int i = 0; i < n; i++) {
            if(nums[i] < 0) {
                negCnt++;
                if(maxNegIdx == -1 or nums[maxNegIdx] < nums[i]) maxNegIdx = i;
            }
        }
        
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] > 0) ans *= nums[i], flag = 1;
            else if(nums[i] < 0 and (negCnt%2 == 0 or maxNegIdx != i)) ans *= nums[i], flag = 1;
            else res *= nums[i];
        }
        
        if(!flag) {
            return res;
        }
        
        return ans;
    }
};
