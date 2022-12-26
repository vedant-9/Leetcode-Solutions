// https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks

class Solution {
public:
    int maximumBags(vector<int>& a, vector<int>& b, int r) {
        int n = a.size();
        for(int i=0;i<n;i++) {
            a[i]-=b[i];
        }
        sort(a.begin(),a.end());
        int ans = 0;
        for(int i=0;i<n and r-a[i]>=0;i++,ans++) {
            r-=a[i];
        }
        return ans;
    }
};