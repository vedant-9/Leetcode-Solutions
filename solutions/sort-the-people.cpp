// https://leetcode.com/problems/sort-the-people

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,int>> v;
        int n = names.size();
        for(int i=0;i<n;i++) {
            v.push_back({heights[i],i});
        }
        sort(v.rbegin(), v.rend());
        vector<string> ans;
        for(int i=0;i<n;i++) {
            ans.push_back(names[v[i].second]);
        }
        return ans;
    }
};