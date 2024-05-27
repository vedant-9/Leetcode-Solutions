class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        
        map<long long, int> mp;
        for(auto x: nums2) mp[x*k]++;
        
        for(auto x: nums1) {
            for(int i = 1; i * i <= x; i++) {
                if(x % i != 0) continue;
                ans += mp[i];
                if(i != x/i) ans += mp[x/i]; 
            }
        }
        
        return ans;
    }
};
