class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        for (auto it : nums)
            pq.push(it);

        long long cnt = 0;
        while (pq.top() < k) {
            long long first = pq.top();
            pq.pop();
            long long second = pq.top();
            pq.pop();
            long long num = 2 * min(first, second) + max(first, second);
            pq.push(num);
            cnt++;
        }
        return cnt;
    }
};
