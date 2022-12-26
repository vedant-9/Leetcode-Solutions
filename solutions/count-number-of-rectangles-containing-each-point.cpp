// https://leetcode.com/problems/count-number-of-rectangles-containing-each-point

class Solution {
public:
    vector<int> countRectangles(vector<vector<int>>& r, vector<vector<int>>& p) {
        vector<vector<int>> mp(101);
        for(auto v:r) {
            mp[v[1]].push_back(v[0]);
        }
        for(auto &v:mp) {
            sort(v.begin(),v.end());
        }
        vector<int> ans;
        for(int i=0;i<p.size();i++) {
            int c=0;
            for(int j=p[i][1];j<101;j++) {
                auto &v = mp[j];
                if(v.empty()) continue;
                // for(auto x:v) {
                //     cout<<x<<"->";
                // }
                // cout<<endl;
                int k = upper_bound(v.begin(),v.end(),p[i][0]-1)-v.begin(); 
                // cout<<k<<endl;
                c += (v.size()-k);
            }
            ans.push_back(c);
        }
        return ans;
    }
};