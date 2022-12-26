// https://leetcode.com/problems/finding-3-digit-even-numbers

class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> res;
        int cnt[10] = {};
        for (auto d : digits)
            ++cnt[d];
        for (int i = 1; i < 10; ++i)
            if (cnt[i] > 0)
                for (int j = 0; j < 10; ++j)
                    if (cnt[j] > 0 + (i == j))
                        for (int k = 0; k < 10; k += 2)
                            if (cnt[k] > 0 + (k == i) + (k == j))
                                res.push_back(i * 100 + j * 10 + k);
        return res;
    }
};