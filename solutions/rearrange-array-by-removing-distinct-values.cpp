class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans, mp(101, 0);
        for(auto x: nums) {
            mp[x]++;
        }
        while(1) {
            int tsz = ans.size();
            for(int i = 0; i < 101; i++) {
                if(mp[i]) ans.push_back(i), mp[i]--;
            }
            if(tsz == ans.size()) break;
        }
        return ans;
    }
};
