// https://leetcode.com/problems/determine-if-two-strings-are-close

class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int n = word1.size(), m = word2.size();
        
        if(n != m) return false;
        
        map<char, int> mp1, mp2;
        for(auto ch: word1) mp1[ch]++;
        for(auto ch: word2) mp2[ch]++;
        
        for(auto it: mp1) {
            if(mp2.find(it.first) == mp2.end()) return false;
        }
        
        for(auto it: mp2) {
            if(mp1.find(it.first) == mp1.end()) return false;
        }
        
        map<int, int> mpp;
        for(auto it: mp1) {
            mpp[it.second]++;
        }
        
        for(auto it: mp2) {
            if(mpp.find(it.second) == mpp.end() or mpp[it.second] == 0) return false;
            mpp[it.second]--;
        }
        
        return true;
    }
};