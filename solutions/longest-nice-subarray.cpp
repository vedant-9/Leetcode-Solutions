// https://leetcode.com/problems/longest-nice-subarray

class Solution {
public:
    int longestNiceSubarray(vector<int>& a) {
        int n = a.size();
        vector<int> cnt(32,0);
        int i = 0, j = 0, mx = 1;
        while(i < n) {
            int f = 0;
            for(int k=0; k<32; k++) {
                if(a[i] & (1<<k))
                    cnt[k]++;
                if(cnt[k]>1) {
                    f=1;
                }
            }
            if(f==0) {
                mx = max(mx, i-j+1);
                i++;
            } else {
                while(j<=i) {
                    int f = 0;
                    for(int k=0; k<32; k++) {
                        if(cnt[k]>1) {
                            f=1;
                        }
                    }
                    if(f==0) break;
                    for(int k=0; k<32; k++) {
                        if(a[j] & (1<<k)) {
                            cnt[k]--;
                        }
                    }
                    j++;
                }
                i++;
            }
        }
        return mx;
    }
};