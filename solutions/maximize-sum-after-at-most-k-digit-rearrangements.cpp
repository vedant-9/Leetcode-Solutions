class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<long long,int>> v;
        int i = 0;
        long long tsum = 0;
        for(auto x: nums) {
            tsum += x;
            string s = to_string(x);
            sort(s.rbegin(), s.rend());
            v.push_back({stol(s) - x, i});
            i++;
        }
        sort(v.begin(), v.end());

        for(int i = n-1; k > 0; k--, i--) {
            tsum += v[i].first;
        }

        return tsum;
    }
};
