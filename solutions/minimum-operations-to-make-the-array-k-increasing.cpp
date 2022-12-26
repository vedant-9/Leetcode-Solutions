// https://leetcode.com/problems/minimum-operations-to-make-the-array-k-increasing

class Solution {
public:
    // make grps of a[i],a[i+k],..
    // find longest non-decreasing subsequence
    
    int kIncreasing(vector<int>& a, int k) {
        int n = a.size();
        
        vector<vector<int>> grps(k);
        for(int i=0;i<n;i++) {
            grps[i%k].push_back(a[i]);
        }
        
        int ans = 0;
        for(auto &v:grps) {
            int sz = v.size();
            
            vector<int> lnds;
            
            for(int i=0;i<sz;i++) {
                int x = v[i];
                
                if(!lnds.size() or lnds.back()<=v[i]) {
                    lnds.push_back(v[i]);
                } else {
                    int idx = upper_bound(lnds.begin(),lnds.end(),x)-lnds.begin();
                    lnds[idx]=x;
                }
            }
            
            ans+=sz-lnds.size();
            
        }
        
        return ans;
    }
};