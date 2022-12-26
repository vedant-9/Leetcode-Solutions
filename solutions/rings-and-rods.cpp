// https://leetcode.com/problems/rings-and-rods

class Solution {
public:
    int countPoints(string s) {
        int n=s.size();
        int cnt[10][3]; memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i+=2) {
            char color=s[i]; int idx=s[i+1]-'0';
            if(color=='R') cnt[idx][0]=1;
            else if(color=='G') cnt[idx][1]=1;
            else cnt[idx][2]=1;
        }
        int ans=0;
        for(int i=0;i<10;i++) {
            if(cnt[i][0] and cnt[i][1] and cnt[i][2]) ans++;
        }
        return ans;
    }
};