// https://leetcode.com/problems/maximum-sum-obtained-of-any-permutation

class Solution {
public:
    const int mod = 1e9+7;
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        
        vector<int> line(n+1,0);
        for(auto &v: requests) {
            line[v[0]]++;
            line[v[1]+1]--;
        }
        
        vector<int> freq;
        int val = 0;
        for(int i=0; i<n; i++) {
            val += line[i];
            freq.push_back(val);
        }
        
        sort(nums.begin(),nums.end());
        sort(freq.begin(),freq.end());
        
        int ans = 0;
        for(int i=0; i<n; i++) {
            ans = (ans + (long long)nums[i]*freq[i])%mod;
        }
        
        return ans;
    }
};