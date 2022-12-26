// https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings

class Solution {
public:
    bool isPalindrome(string s, int l, int r) {
        while(l < r) {
            if (s[l] != s[r]) return false;
            l++; r--;
        }
        return true;
    }
    int maxPalindromes(string s, int k) {
        int ans = 0, n = s.length();
        vector<int> dp(n+1, 0);
        for(int i = k-1; i < n; i++) {
            dp[i+1] = dp[i];
            if (isPalindrome(s, i-k+1, i))       
                dp[i+1] = max(dp[i+1], 1 + dp[i-k+1]);
            if (i-k>=0 && isPalindrome(s, i-k, i)) 
                dp[i+1] = max(dp[i+1], 1 + dp[i-k]);
        }
        return dp[n];
    }
};