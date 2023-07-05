class Solution {
public:
    int longestSubarray(vector<int>& a) {
        int i = 0, j, k = 1;
        for (j = 0; j < a.size(); ++j) {
            if (a[j] == 0) k--;
            if (k < 0 && a[i++] == 0) k++;
        }
        return j - i - 1;
    }
};
