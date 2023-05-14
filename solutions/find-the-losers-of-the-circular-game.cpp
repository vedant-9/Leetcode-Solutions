class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        set<int> st;
        int x = 1, i = 1;
        while(st.find(x) == st.end()) {
            st.insert(x);
            x = (x + i*k)%n;
            if(x == 0) x = n;
            i++;
        }
        vector<int> ans;
        for(int i = 2; i <= n; i++) {
            if(st.find(i) == st.end())
                ans.push_back(i);
        }
        return ans;
    }
};
