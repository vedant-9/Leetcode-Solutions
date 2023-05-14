class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        for(auto &v: nums) 
            sort(v.begin(), v.end());
        vector<int> temp;
        int m = nums.size(), n = nums[0].size();
        int score = 0;
        for(int j = 0; j < n; j++) {
            int sc = 0;
            for(int i = 0; i < m; i++) {
                sc = max(sc, nums[i][j]);
            }
            score += sc;
        }
        return score;
    }
};
