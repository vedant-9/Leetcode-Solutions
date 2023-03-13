class Solution {
public:
    int maxScore(vector<int>& nums) {
        int n = nums.size();
        long long sum = 0, cnt = 0;
        vector<int> neg;
        for(auto x: nums) {
            if(x > 0) sum += x, cnt++;
            else neg.push_back(x);
        }
        sort(neg.rbegin(), neg.rend());
        for(auto x: neg) {
            sum += x;
            if(sum <= 0) break;
            cnt++;
        }
        return cnt;
    }
};
