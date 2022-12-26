// https://leetcode.com/problems/find-all-lonely-numbers-in-the-array

class Solution {
public:
    vector<int> findLonely(vector<int>& a) {
        sort(a.begin(),a.end());
        vector<int> ans;
        map<int,int> m; for(auto x:a) m[x]++;
        for(int i=0;i<a.size();i++) {
            if(m.find(a[i]-1)==m.end() and m.find(a[i]+1)==m.end() and m[a[i]]==1) ans.push_back(a[i]);
        }
        return ans;
    }
};