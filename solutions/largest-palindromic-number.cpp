// https://leetcode.com/problems/largest-palindromic-number

class Solution {
public:
    string largestPalindromic(string s) {
        int cnt[10] = {0};
        for(auto &ch:s) cnt[ch-'0']++;
        
        string res;
        for(int i=9;i>=0;i--) {
            if(res.empty() and i==0) continue;
            int c = cnt[i]/2;
            cnt[i]%=2;
            res.append(string(c,(char)('0'+i)));
        }
        
        int f=0;
        for(int i=9;i>=0;i--) {
            if(cnt[i]) {
                res.push_back((char)('0'+i));
                f=1;
                break;
            }
        }
        
        
        string t = res;
        if(f==1) t.pop_back();
        reverse(t.begin(),t.end());
        res += t;
        
        return res;
    }
};