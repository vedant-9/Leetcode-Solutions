class Solution {
public:
    // rem is i, s is string of i*i
    bool check(int idx, string s, int rem) {
        int sz = s.size();
        if(idx >= sz && rem == 0) return true;
        if(rem < 0) return false;
        
        int num = 0;
        for(int i = idx; i < sz; i++) {
            num = (num*10)+(s[i]-'0');
            if(check(i+1, s, rem - num)) return true;
        }
        return false;
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for(int i = 1; i <= n; i++) {
            if(check(0, to_string(i*i), i)) {
                sum += i*i;
            }
        }
        return sum;
    }
};
