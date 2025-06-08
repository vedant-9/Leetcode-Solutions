class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<string> vst;
        for (int i = 1; i <= n; i++) {
            vst.push_back(to_string(i));
        }
        sort(vst.begin(), vst.end());
        vector<int> ans;
        for (auto s : vst) {
            ans.push_back(stoi(s));
        }
        return ans;
    }
};
