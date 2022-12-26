// https://leetcode.com/problems/merge-similar-items

class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<int> count(1001,0);
        for(auto &v: items1) {
            count[v[0]] += v[1];
        }
        for(auto &v: items2) {
            count[v[0]] += v[1];
        }
        
        vector<vector<int>> ans;
        for(int i=0; i<1001; i++) {
            if(count[i]) 
                ans.push_back({i,count[i]});
        }
        
        return ans;
    }
};