class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& d) {
        sort(d.begin(), d.end());
        vector<int> cnt;
        for(auto x: d) {
            int c = 0;
            for(auto y: nums) {
                if(y%x == 0) c++;
            }
            cnt.push_back(c);
        }
        int mx = 0, mxi = 0;
        for(int i = 0; i<d.size(); i++) {
            if(cnt[i] > mx) {
                mxi = i;
                mx = cnt[i];
            }
        }
        return d[mxi];
    }
};
