// https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations

class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        set<int> st;
        for(auto x: nums) {
            st.insert(x);
            int r = 0;
            while(x) {
                r = r*10+x%10;
                x/=10;
            }
            st.insert(r);
        }
        return (int)st.size();
    }
};