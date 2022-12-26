// https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups

class Solution {
public:
    int minGroups(vector<vector<int>>& v) {
        sort(v.begin(), v.end(), [](const vector<int> &x, const vector<int> &y) {
            // if(x[0] == y[0]) return x[1] > y[1];
            return x[0] < y[0];
        });
        multiset<int> st;
        for(auto &x: v) {
            auto it = st.lower_bound(x[0]); 
            if(st.empty()) {
                st.insert(x[1]+1); continue;
            }
            if(it == st.end()) {
                it--;
                if(*it <= x[0]) {
                    st.erase(it); st.insert(x[1]+1);
                } 
            } else if(it == st.begin()) {
                if(*it > x[0]) st.insert(x[1]+1);
                else {
                    st.erase(it); st.insert(x[1]+1);
                }
            }  else {
                if(*it != x[0]) it--;
                if(*it <= x[0]) {
                    st.erase(it); st.insert(x[1]+1);
                } 
            }
        }
        return (int)st.size();
    }
};