class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        // sliding window 
        int left = 0, right = 0, n = s.length(), curCost = 0, maxLength = 0;
        while(right < n) {
            curCost += abs(t[right] - s[right]);
            while(curCost > maxCost) {
                curCost -= abs(t[left] - s[left]);
                left++;
            }
            maxLength = max(maxLength, right - left + 1);
            right++;
        }
        return maxLength;
    }
};
