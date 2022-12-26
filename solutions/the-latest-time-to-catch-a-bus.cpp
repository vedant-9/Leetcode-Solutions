// https://leetcode.com/problems/the-latest-time-to-catch-a-bus

class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& b, vector<int>& p, int c) {
        int n = b.size(), m = p.size();
        sort(b.begin(),b.end());
        sort(p.begin(),p.end());
        int j = 0, cnt, prev = 0, ans = 0;
        for(int i=0;i<n;i++) {
            cnt = 0;
            while(j<m and p[j]<=b[i] and cnt<c) {
                if(p[j]-prev>1) 
                    ans = p[j]-1;
                prev = p[j];
                j++;
                cnt++;
            }
            if(cnt<c and b[i]>prev) 
                ans = b[i];
        }
        return ans;
    }
};