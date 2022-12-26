// https://leetcode.com/problems/replace-the-substring-for-balanced-string

class Solution {
public:
    // Sliding Window 
    // Consider a window - Outside window all QWER count is <=n/4 
    // implies we can convert window into required counts
    int balancedString(string s) {
        int n = s.size(), k = n/4;
        
        unordered_map<int, int> count;
        for(auto &ch: s) {
            count[ch]++;
        }
        
        int minLen = n, j = 0;
        for(int i=0; i<n; i++) {
            count[s[i]]--;
            while(j<n and count['Q']<=k and count['W']<=k and count['E']<=k and count['R']<=k) {
                minLen = min(minLen, i-j+1);
                count[s[j]]++;
                j++;
            }
        }
        
        return minLen;
    }
};