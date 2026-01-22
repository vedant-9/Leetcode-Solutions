class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int> t;
        int ops = 0;
        t = nums;
        while (true) {
            nums.clear();
            int f = 0;
            for (int i = 1; i < t.size(); i++) {
                if (t[i - 1] > t[i]) {
                    f = 1;
                    break;
                }
            }
            if (f == 0)
                break;
            int min_sum = 1e5, min_sum_ind = -1;
            for (int i = 0; i < t.size() - 1; i++) {
                if ((t[i] + t[i + 1]) < min_sum) {
                    min_sum = t[i] + t[i + 1];
                    min_sum_ind = i;
                }
            }
            for (int i = 0; i < t.size() - 1; i++) {
                if (i - 1 == min_sum_ind)
                    continue;
                if (i == min_sum_ind) {
                    nums.push_back(t[i] + t[i + 1]);
                } else {
                    nums.push_back(t[i]);
                }
            }
            if (min_sum_ind != t.size() - 2)
                nums.push_back(t.back());
            t = nums;
            ops++;
        }
        return ops;
    }
};
