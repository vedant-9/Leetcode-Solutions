class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int> s;
        for(auto x: nums) s.insert(x);
        int sz = s.size(), n = nums.size(), ans = 0;
        
        for(int i = 0; i < n; i++) {
            set<int> st;
            for(int j = i; j < n; j++) {
                st.insert(nums[j]);
                if(st.size() == sz) ans++;
            }
        }
        
        return ans;
    }
};
