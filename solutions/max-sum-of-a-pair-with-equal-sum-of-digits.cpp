// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits

class Solution {
public:
    int maximumSum(vector<int>& a) {
        vector<vector<int>> cnt(100);
        for(auto x:a) {
            int s = 0, y = x;
            while(x) {
                s+=x%10; x/=10;
            }
            cnt[s].push_back(y);
        }
        int mx = -1;
        for(int i=0;i<100;i++) {
            if(cnt[i].size()<2) continue;
            sort(cnt[i].rbegin(),cnt[i].rend());
            mx = max(mx, cnt[i][0]+cnt[i][1]);
        }
        return mx;
    }
};