// https://leetcode.com/problems/longest-duplicate-substring

class Solution {
public:
    // TODO
    int p = INT_MAX / 26 / 26 * 26 - 1; // = 82595499
    // order of 26 mod 82595499 is 11799354 > 50000, so this choice should result in minimum collision
    string longestDupSubstring(string S) {
        int hi = S.size(), lo = 0, idx = 0;
        while (hi - lo > 1) {
            auto mid = (hi + lo) / 2;
            int pow = 1, h = 0;
            for (int i = mid - 1; i >= 0; --i) {
                h += (S[i] - 'a') * pow, h %= p;
                pow *= 26, pow %= p;
            }
            unordered_multimap<int,int> h2i = {{h,0}}; // hash to indices
            auto i = 0;
            for ( ; i + mid < S.size(); ++i) {
                h *= 26, h %= p;
                h += (S[i+mid] - 'a') - (S[i] - 'a') * pow, h %= p;
                h += p, h %= p;
                auto its = h2i.equal_range(h);
                auto it = its.first;
                for ( ; it != its.second; ++it) {
                    auto j = i+1, k = it->second;
                    for ( ; j < i + mid; ++j, ++k) {
                        if (S[j] != S[k]) break;
                    }
                    if (j == i + mid) break;
                }
                if (it != its.second) break;
                h2i.insert({h,i+1});
            }
            if (i + mid < S.size())
                lo = mid, idx = i + 1;
            else hi = mid;
        }
        return S.substr(idx,lo);
    }
};