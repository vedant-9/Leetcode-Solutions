// https://leetcode.com/problems/substring-with-concatenation-of-all-words

class Solution {
public:
    bool checkSubstring(string w, map<string, int> count, int wordLen) {
        for(int i=0; i<w.size(); i+=wordLen) {
            string t = w.substr(i,wordLen);
            if(count.find(t)==count.end())
                return false;
            count[t]--;
            if(count[t]==0)
                count.erase(t);
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        int wordLen = words[0].size();
        int totalLen = wordLen * words.size();
        map<string, int> count;
        for(auto word: words) {
            count[word]++;
        }
        
        vector<int> ans;
        for(int i=0; i+totalLen<=s.size(); i++) {
            if(checkSubstring(s.substr(i,totalLen), count, wordLen)) {
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};