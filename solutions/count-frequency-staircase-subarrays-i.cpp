class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n = nums.size(), ans = 0;
        for(int i = 0; i < n; i++) {
            unordered_map<int, int> mp;
            vector<int> fseen;
            for(int j = i; j < n; j++) {
                if(mp.find(nums[j]) == mp.end()) fseen.push_back(j);
                mp[nums[j]]++;
                int c = 1, f = 0, k = 0;
                for(int k = 0; k < fseen.size(); k++) {
                    auto it = mp.find(nums[fseen[k]]);
                    if(it->second != c) {
                        f = 1; break;
                    }
                    c++;
                }
                if(f == 0) ans++;
            }
        }
        return ans;
    }
};
