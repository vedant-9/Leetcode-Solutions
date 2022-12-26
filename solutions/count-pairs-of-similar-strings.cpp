// https://leetcode.com/problems/count-pairs-of-similar-strings

class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0, n = words.size();
        for(int i=0; i<n; i++) {
            set<char> st1;
            for(auto x: words[i]) st1.insert(x);
            string t = "";
            for(auto x: st1) t += x;
            words[i] = t;
        }
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(words[i] == words[j]) ans++;
            }
        }
        return ans;
    }
};