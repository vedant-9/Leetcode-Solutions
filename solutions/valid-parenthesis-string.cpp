class Solution {
public:
    bool checkValidString(string s) {
        // balances range
        int low = 0, high = 0;
        for(auto ch: s) {
            if(ch == '(') low++, high++;
            else if(ch == ')') low--, high--;
            else low--, high++;
            if(high < 0) return false;
            low = max(low, 0);
        }
        // cout << low << " " << high;
        return low == 0;
    }
};
