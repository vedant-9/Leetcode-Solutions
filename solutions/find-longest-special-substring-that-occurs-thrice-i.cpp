class Solution {
public:
    int maximumLength(string st) {
        map<pair<char, int>, int> mps;
        int count = 0;

        for (int i = 0; i < st.length(); i++) {
            count = 1;
            mps[{st[i], count}]++;

            for (int j = i; j < st.length(); j++) {
                if (st[j] == st[j + 1]) {
                    count++;
                    mps[{st[i], count}]++;
                } else {
                    break;
                }
            }
        }

        int ans1 = 0;

        for (auto x : mps) {
            if (x.second >= 3) {
                ans1 = max(x.first.second, ans1);
            }
        }

        return (ans1 == 0) ? -1 : ans1;
    }
};
