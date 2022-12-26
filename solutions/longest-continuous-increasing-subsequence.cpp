// https://leetcode.com/problems/longest-continuous-increasing-subsequence

class Solution {
public:
    int findLengthOfLCIS(vector<int>& a) {
        int maxLen = 1, curLen = 1;
        int n = a.size();
        for(int i=1; i<n; i++) {
            if(a[i-1] < a[i]) curLen++;
            else maxLen = max(maxLen, curLen), curLen = 1;
        }
        maxLen = max(maxLen, curLen);
        return maxLen;
    }
};