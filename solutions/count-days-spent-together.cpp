// https://leetcode.com/problems/count-days-spent-together

class Solution {
public:
    int countDaysTogether(string aa, string al, string ba, string bl) {
        string mxa = max(ba, aa);
        string mxl = min(al, bl);
        if(mxa > mxl) return 0;
        int m[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sm = (mxa[0]-'0')*10 + (mxa[1]-'0');
        int em = (mxl[0]-'0')*10 + (mxl[1]-'0');
        int ans = 0;
        if(sm == em) 
            ans = ((mxl[3]-'0')*10 + (mxl[4]-'0')) - ((mxa[3]-'0')*10 + (mxa[4]-'0')) + 1;
        else 
            ans += (m[sm] - ((mxa[3]-'0')*10 + (mxa[4]-'0')) + 1);
        for(int i=sm+1; i<em; i++) {
            ans += m[i];
        }
        if(sm != em) 
            ans += ((mxl[3]-'0')*10 + (mxl[4]-'0'));
        return ans;
    }
};