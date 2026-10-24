class Solution {
public:
    int peakValleyDifference(vector<int>& nums) {
        int psum = 0, vsum = 0;
        int n = nums.size();
        for(int i = 1; i < n-1; i++) {
            if(nums[i] > nums[i-1] and nums[i] > nums[i+1]) psum += nums[i];
            if(nums[i] < nums[i-1] and nums[i] < nums[i+1]) vsum += nums[i];
        }
        return psum - vsum;
    }
};
