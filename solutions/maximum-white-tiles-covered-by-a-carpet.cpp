// https://leetcode.com/problems/maximum-white-tiles-covered-by-a-carpet

class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& a, int cl) {
        sort(a.begin(),a.end());
        int ans=0,k=0,tot=0;
        for(auto x:a) {
            int from = x[0];
            int to = x[0]+cl-1;
            while(k<a.size() and a[k][1]<to) {
                tot+=(a[k][1]-a[k][0]+1);
                k++;
            }
            if(k==a.size() or a[k][0]>to) {
                ans=max(ans,tot);
            } else {
                ans=max(ans,tot+(to-a[k][0]+1));
            }
            tot-=(x[1]-x[0]+1);
        }
        return ans;
    }
};