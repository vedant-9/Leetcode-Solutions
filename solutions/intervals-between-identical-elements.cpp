// https://leetcode.com/problems/intervals-between-identical-elements

class Solution {
public:
    vector<long long> getDistances(vector<int>& a) {
        int n = a.size();
        vector<long long> ans(n);
        map<int,vector<int>> m;
        for(int i=0;i<n;i++) {
            m[a[i]].push_back(i);
        }
        
        for(auto &it:m) {
            int x = it.first;
            auto v = it.second;
            
            int sz = v.size();
            vector<long long> right(sz);
            right[sz-1]=0;
            for(int i=sz-2;i>=0;i--) {
                right[i]=right[i+1]+v[i+1];
            }
            
            long long lsum = 0;
            for(int i=0;i<sz;i++) {
                int j = v[i];
                
                ans[j] = (long long)((long long)j*(2*i-sz+1)-lsum+right[i]);
                
                lsum+=v[i];
            }
        }
        return ans;
    }
};