// https://leetcode.com/problems/find-all-good-indices

class Solution {
public:
    vector<int> goodIndices(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dec(n+1, 1), inc(n+1, 1);
        for(int i=1;i<n;i++) {
            if(a[i-1]>=a[i]) 
                dec[i]=dec[i-1]+1;
        }
        for(int i=n-2;i>=0;i--) {
            if(a[i]<=a[i+1]) 
                inc[i]=inc[i+1]+1;
        }
        vector<int> ans;
        for(int i=k;i<n-k;i++) {
            if(dec[i-1]>=k and inc[i+1]>=k) 
                ans.push_back(i);
        }
        return ans;
    }
};