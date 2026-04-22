class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> ans;
        for (auto q : queries) {
            int flag = 0;
            for (auto d : dictionary) {
                int cnt = 0;
                for (int i = 0; i < d.size(); i++) {
                    if (q[i] != d[i])
                        cnt++;
                }
                if (cnt <= 2) {
                    flag = 1;
                    break;
                }
            }

            if (flag == 1) {
                ans.push_back(q);
            }
        }
        return ans;
    }
};
