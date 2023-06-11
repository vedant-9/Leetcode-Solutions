class Solution {
public:
    string smallestString(string s) {
        int n = s.size(), i = 0;
        while(i < n and s[i] == 'a') i++;
        int f = 0;
        while(i < n and s[i] != 'a') {
            s[i]--;
            f = 1;
            i++;
        }
        if(!f) {
            if(i >= n) s[n-1] = 'z';
            else s[i] = 'z';
        }
        return s;
    }
};
