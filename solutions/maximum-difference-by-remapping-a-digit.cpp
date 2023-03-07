class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        int n = s.size();
        int i = 0;
        while(i < n and s[i] == '9') i++;
        string mx = s, mn = s;
        if(i < n) {
            char ch = s[i];
            while(i < n) {
                if(mx[i] == ch) mx[i] = '9'; i++;
            }
        }
        char ch = s[0];
        i = 0;
        while(i < n) { 
            if(mn[i] == ch) mn[i] = '0'; i++;
        }
        return stoi(mx)-stoi(mn);
    }
};
