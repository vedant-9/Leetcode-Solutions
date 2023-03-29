class Solution {
public:
    vector<int> getPrimes() {
        vector<int> p, spf(1001, 0);
        p.push_back(2);
        for (int i = 3; i < 32; ++i)
            if (!spf[i])
                for (int j = i * i; j <= 1000; j += i)
                    spf[j] = true;
        for (int i = 3; i <= 1000; i += 2)
            if (!spf[i])
                p.push_back(i);
        return p;
    }
    bool primeSubOperation(vector<int>& nums) {
        auto p = getPrimes();
        for (int i = 0; i < nums.size(); ++i) {
            auto it = lower_bound(p.begin(), p.end(), nums[i] - (i ? nums[i - 1] : 0));
            if (it != p.begin())
                nums[i] -= *prev(it);
            if (i && nums[i] <= nums[i - 1])
                return false;
        }
        return true;
    }
};
