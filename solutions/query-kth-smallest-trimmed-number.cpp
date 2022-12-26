// https://leetcode.com/problems/query-kth-smallest-trimmed-number

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& a, vector<vector<int>>& quer) {
        int sz = a.size(), n = a[0].size();
        vector<int> ans;
        for(auto q:quer) {
            int k = q[0], t = q[1];
            vector<pair<string,int>> v;
            for(int i=0;i<sz;i++) {
                v.push_back({a[i].substr(n-t),i});
            }
            sort(v.begin(),v.end());
            ans.push_back(v[k-1].second);
        }
        return ans;
    }
};