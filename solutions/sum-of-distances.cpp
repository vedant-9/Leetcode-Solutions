class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        map<int, long long> sum, cnt;
        vector<long long> ans(n, 0);
        
        for(int i = 0; i < n; i++) {
            ans[i] += cnt[nums[i]] * i - sum[nums[i]];
            cnt[nums[i]]++;
            sum[nums[i]] += i;
        }
        
        sum.clear(); cnt.clear();
        
        for(int i = n-1; i >= 0; i--) {
            ans[i] += sum[nums[i]] - cnt[nums[i]] * i;
            cnt[nums[i]]++;
            sum[nums[i]] += i;
        }
        
        return ans;
    }
};
