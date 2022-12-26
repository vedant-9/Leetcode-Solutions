// https://leetcode.com/problems/most-popular-video-creator

class Solution {
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) {
        map<string, int> cnt;
        int n = ids.size();
        for(int i=0; i<n; i++) {
            cnt[creators[i]]+=views[i];
        }
        int maxCnt = 0;
        for(auto &it: cnt) {
            maxCnt = max(maxCnt, it.second);
        }
        map<string, int> idx;
        for(int i=0; i<n; i++) {
            string c = creators[i];
            if(cnt[c] == maxCnt) {
                if(idx.find(c) == idx.end()) idx[c] = i;
                else {
                    if(views[idx[c]] < views[i]) idx[c] = i;
                    else if(views[idx[c]] == views[i] and ids[idx[c]] > ids[i]) idx[c] = i; 
                }
            }
        }
        vector<vector<string>> ans;
        for(auto &it: idx) {
            ans.push_back({it.first, ids[it.second]});
        }
        return ans;
    }
};