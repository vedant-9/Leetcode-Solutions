class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int,int> mp;
        int ans = 0;
        for(int i = 0;i<nums.size();i++){
                mp[nums[i] - k] ++;
                mp[nums[i] + k + 1] --;

        }
        int prev = 0;
        for(auto [a,b] : mp){
                prev += b;
                ans = max(ans,prev);
        }
        return ans;
    }
};
