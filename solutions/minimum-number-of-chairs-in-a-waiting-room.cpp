class Solution {
public:
    int minimumChairs(string s) {
        int cnt = 0, ans = 0;
        for(auto ch: s) {
            if(ch == 'E') cnt++;
            else cnt--;
            ans = max(ans, cnt);
        }
        return ans;
    }
};
