// https://leetcode.com/problems/plates-between-candles

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& qu) {
        int n=s.size(); int left[n],right[n]; left[0]=right[n-1]=-1;
        for(int i=1;i<n;i++) {
            left[i]=left[i-1];
            if(s[i]=='|') left[i]=i;
        } 
        for(int i=n-2;i>=0;i--) {
            right[i]=right[i+1];
            if(s[i]=='|') right[i]=i;
        }
        int cnt[n+1]; cnt[0]=0;
        for(int i=1;i<=n;i++) {
            cnt[i]=cnt[i-1];
            if(s[i-1]=='*') cnt[i]++;
        }
        vector<int> ans;
        for(auto q:qu) {
            int l=q[0],r=q[1];
            l=right[l],r=left[r];
            if(l<=r)
                ans.push_back(cnt[r+1]-cnt[l]);
            else
                ans.push_back(0);
        }
        return ans;
    }
};