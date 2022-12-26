// https://leetcode.com/problems/find-subarrays-with-equal-sum

class Solution {
public:
    bool findSubarrays(vector<int>& a) {
        int n = a.size();
        set<int> st;
        for(int i=0;i<n-1;i++) {
            int sum = a[i]+a[i+1];
            if(st.find(sum)!=st.end())
                return 1;
            st.insert(sum);
        }
        return 0;
    }
};