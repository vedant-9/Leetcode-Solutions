class Solution {
public:        
    set<string> wordSet;
    set<string> ansSet;
    int n;
    string s;

    
    void rec(int i, string cur, string cur_ans) {
        if(i == n) {
            if(cur == "") {
                if(cur_ans.length()) cur_ans.pop_back();
                ansSet.insert(cur_ans);
            }
            if(wordSet.find(cur) != wordSet.end()) {
                cur_ans += cur;
                ansSet.insert(cur_ans);
            }
            return;
        }
        cur += s[i];
        if(wordSet.find(cur) != wordSet.end()) {
            rec(i+1, "", cur_ans+cur+" ");
        }
        rec(i+1, cur, cur_ans);
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->n = s.length();
        for(auto word: wordDict) {
            wordSet.insert(word);
        }
        rec(0, "", "");
        vector<string> ansVec;
        for(auto it: ansSet) {
            ansVec.push_back(it);
        }
        return ansVec;
    }
};
