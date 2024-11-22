class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        // Max count of complementary pattern
        map<string, int> freq;
        for(auto &v: matrix) {
            string pat = "";
            for(int i = 1; i < v.size(); i++) {
                if(v[i] != v[0]) pat += "1";
                else pat += "0";
            }
            freq[pat]++;
        }
        int ans = 0;
        for(auto it: freq) {
            ans = max(ans, it.second);
        }
        return ans;
    }
};
