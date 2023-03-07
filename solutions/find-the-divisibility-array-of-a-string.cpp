class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> ans(n, 0);
        long long rem = 0;
        for(int i=0; i<n; i++) {
            rem = (rem * 10 + (word[i]-'0')) % m;
            ans[i] = (rem == 0);
        }
        return ans;
    }
};
