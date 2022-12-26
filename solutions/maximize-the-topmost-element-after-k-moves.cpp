// https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves

class Solution {
public:
    int maximumTop(vector<int>& a, int k) {
        int n = a.size();
        if(n==1 and k>1){
            if(k%2!=0) return -1;
            return a[0];
        }
        if(k<n) {
            int mx=-1;
            for(int i=0;i<k-1;i++) mx=max(mx,a[i]);
            mx=max(mx,a[k]);
            return mx;
        }
        if(k==n) {
            int mx=-1;
            for(int i=0;i<k-1;i++) mx=max(mx,a[i]);
            return mx;
        }
        int mx=-1;
        for(int i=0;i<n;i++) mx=max(mx,a[i]);
        return mx;
    }
};