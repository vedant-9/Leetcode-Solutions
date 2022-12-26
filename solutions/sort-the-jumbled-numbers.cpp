// https://leetcode.com/problems/sort-the-jumbled-numbers

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n=nums.size();
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++) {
            int y=0;
            string x=to_string(nums[i]);
            for(auto c:x) {
                y=y*10+mapping[c-'0'];
            }
            v.push_back({y,i});
        }
        sort(v.begin(),v.end());
        vector<int> res;
        for(auto p:v) res.push_back(nums[p.second]);
        return res;
    }
};