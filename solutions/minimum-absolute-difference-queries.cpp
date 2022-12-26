// https://leetcode.com/problems/minimum-absolute-difference-queries

class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        
        // prefix sum of freq
        vector<vector<int>> pre(n+1, vector<int>(101, 0));
        
        for(int i=1; i<=n; i++) {
            pre[i] = pre[i-1];
            pre[i][nums[i-1]]++;
        }
        
        vector<int> ans;
        for(auto &q: queries) {
            int mn = INT_MAX, l = q[0], r = q[1]+1;
            int prev = -1;
            for(int j=0; j<101; j++) {
                int f=0;
                if(pre[r][j]-pre[l][j] <= 0) continue; 
                if(prev != -1 and j-prev<mn) mn = j-prev;
                prev = j;
            }
            if(mn == INT_MAX) mn = -1;
            ans.push_back(mn);
        }
        
        return ans;
    }
};