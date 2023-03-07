class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        // find least significant bit which cannot be set
        unordered_set<int> m;
        for (int n : nums)
            if ((n & (n - 1)) == 0)
                m.insert(n);
        int res = 1;
        while (m.count(res))
            res <<= 1;
        return res;
    }
};
