// https://leetcode.com/problems/number-of-zero-filled-subarrays

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long ans = 0, n = a.size(), c = 0;
        for(int i=0;i<n;i++) {
            if(a[i]==0) c++;
            else {
                ans += (c*(c+1))/2;
                c=0;
            }
        }
        ans += (c*(c+1))/2;
        return ans;
    }
};