// https://leetcode.com/problems/number-of-distinct-averages

class Solution {
public:
    int distinctAverages(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<double> st;
        for(int i=0; i<n/2; i++) {
            st.insert((nums[i] + nums[n-i-1])*1.0/2);
        }
        return (int)st.size();
    }
};