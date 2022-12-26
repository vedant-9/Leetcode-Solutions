// https://leetcode.com/problems/maximum-score-from-performing-multiplication-operations

class Solution {
public:
    // Rec + Memo solution
    int rec(int cur, int left, vector<int> &nums, vector<int> &muls, vector<vector<int>> &dp) {
        if(cur == muls.size()) return 0;
        
        int &ans = dp[cur][left];
        if(ans != INT_MIN) return ans;
        
        // pick x as left
        ans = rec(cur+1, left+1, nums, muls, dp) + nums[left]*muls[cur];
        
        // pick x as right
        int right = nums.size()-1-(cur-left);
        ans = max(ans, rec(cur+1, left, nums, muls, dp) + nums[right]*muls[cur]);
        
        return ans;
    }
    
    int maximumScore(vector<int>& nums, vector<int>& muls) {
        int n = nums.size(), m = muls.size();
        vector<vector<int>> dp(m+1, vector<int>(m+1, INT_MIN));
        return rec(0, 0, nums, muls, dp);
    }
};