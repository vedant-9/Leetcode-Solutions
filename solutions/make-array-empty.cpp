class Solution {
public:
    long long countOperationsToEmptyArray(vector<int>& a) {
        unordered_map<int, int> pos;
        long long n = a.size(), res = n;
        for (int i = 0; i < n; ++i)
            pos[a[i]] = i;
        sort(a.begin(), a.end());
        for (int i = 1; i < n; ++i)
            if (pos[a[i]] < pos[a[i - 1]])
                res += n - i;
        return res;
    }
};
