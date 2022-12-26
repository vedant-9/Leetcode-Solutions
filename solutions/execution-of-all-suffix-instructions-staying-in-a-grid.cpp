// https://leetcode.com/problems/execution-of-all-suffix-instructions-staying-in-a-grid

class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& sp, string s) {
        int sx = sp[0], sy = sp[1], m = s.length();
            
        vector<int> ans;
        for(int i=0;i<m;i++) {
            int cnt=0;
            int x=sx,y=sy;
            for(int j=i;j<m;j++) {
                if(s[j]=='L') y--;
                else if(s[j]=='R') y++;
                else if(s[j]=='U') x--;
                else x++;
                if(x<0 or y<0 or x>=n or y>=n) {
                    break;
                }
                cnt++;
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};