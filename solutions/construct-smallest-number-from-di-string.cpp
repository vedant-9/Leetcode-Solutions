// https://leetcode.com/problems/construct-smallest-number-from-di-string

class Solution {
public:
    string num = "123456789";
    string pat;
    int k;
    string ans = ".";
    
    void rec(string &cur, vector<int> &vis) {
        if(cur.size()==k+1) {
            int f=0;
            for(int i=0;i<k;i++) {
                if((pat[i]=='I' and cur[i]>cur[i+1]) or (pat[i]=='D' and cur[i]<cur[i+1])) {
                    f=1; break;
                }
            }
            if(f==0) {
                if(ans=="." or ans>cur) 
                    ans=cur;
            }
            return;
        }
        for(int i=1;i<=9;i++) {
            if(vis[i]) continue;
            cur += (char)('0'+i);
            vis[i]=1;
            rec(cur,vis);
            vis[i]=0;
            cur.pop_back();
        }
    }
    
    string smallestNumber(string p) {
        k = p.size(); 
        pat = p;
        string cur = "";
        vector<int> vis(10,0);
        rec(cur,vis);
        return ans;
    }
};