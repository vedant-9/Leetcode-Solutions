// https://leetcode.com/problems/longest-subsequence-with-limited-sum

class Solution {
public:
    vector<int> answerQueries(vector<int>& a, vector<int>& q) {
        int n = a.size();
        sort(a.begin(),a.end());
        for(int i=1;i<n;i++) a[i]+=a[i-1];
        
        vector<int> ans;
        for(auto x:q) {
            auto j = lower_bound(a.begin(),a.end(),x)-a.begin();
            if(j==n or a[j]>x) j--;
            ans.push_back(j+1);
        }
        return ans;
    }
};