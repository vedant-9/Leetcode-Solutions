class Solution {
public:
    long long findScore(vector<int>& nums) {
        long long score = 0;
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(int i = 0; i < n; i++) {
            pq.push({nums[i], i});
        }
        while(!pq.empty()) {
            auto cur = pq.top(); pq.pop();
            if(nums[cur.second] == -1) continue;
            score += cur.first;
            nums[cur.second] = -1;
            if(cur.second - 1 >= 0) nums[cur.second-1] = -1;
            if(cur.second + 1 < n) nums[cur.second+1] = -1;
        }
        return score;
    }
};
