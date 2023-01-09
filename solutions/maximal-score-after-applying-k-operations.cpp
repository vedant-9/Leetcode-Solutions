class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto x: nums) pq.push(x);
        long long score = 0;
        while(k--) {
            auto x = pq.top(); pq.pop();
            score += x;
            pq.push((x+2)/3);
        }
        return score;
    }
};
