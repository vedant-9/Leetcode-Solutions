class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> st;
        int n = nums.size();
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] <= k) st.insert(nums[i]);
            if(st.size() == k) return n-i;
        }
        return 0;
    }
};
