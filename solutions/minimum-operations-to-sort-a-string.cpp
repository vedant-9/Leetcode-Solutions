class Solution {
public:
    int minOperations(string s) {
        string t = s;
        sort(t.begin(), t.end());

        int low_cnt = 0, high_cnt = 0;
        int i = 0, j = s.size() - 1;
        while(i < t.size() and t[0] == t[i]) i++, low_cnt++;
        while(j >= 0 and t.back() == t[j]) j--, high_cnt++;

        if(s == t) return 0;
        if(s.size() == 2) return -1;
        if(s[0] == t[0] or s.back() == t.back()) return 1;
        if(s[0] == t.back() and t[0] == s.back() and low_cnt == 1 and high_cnt == 1) return 3;
        return 2; 
    }
};
