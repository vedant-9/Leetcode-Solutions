class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        sort(happiness.rbegin(), happiness.rend());
        long long ans = 0;
        for(int i = 0; i < k; i++) {
            if(happiness[i] - i < 0) break;
            ans += (happiness[i] - i);
        }
        return ans;
    }
};
