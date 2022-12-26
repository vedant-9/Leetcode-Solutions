// https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero

class Solution {
public:
    int minOperations(vector<int>& a, int x) {
        int n = a.size();
        vector<int> pre(n); pre[0]=a[0];
        for(int i=1;i<n;i++) {
            pre[i]=pre[i-1]+a[i];
        }
        int sum=0,mn=INT_MAX;
        for(int i=n;i>=0;i--) {
            if(i!=n) sum+=a[i];
            if(sum>x) break;
            if(sum==x) {
                mn=min(mn,n-i); continue;
            }
            int j = lower_bound(pre.begin(),pre.end(),x-sum)-pre.begin();
            if(j!=n and j<i and pre[j]==x-sum) mn=min(mn,j+1+n-i);  
        }
        if(mn==INT_MAX) mn=-1;
        return mn;
    }
};