// https://leetcode.com/problems/construct-target-array-with-multiple-sums

class Solution {
public:
    bool isPossible(vector<int>& a) {
        // 
        long total = 0;
        int n = a.size();
        priority_queue<int> pq(a.begin(), a.end());
        for (int x : a)
            total += x;
        while (true) {
            int x = pq.top(); pq.pop();
            total -= x;
            if (x == 1 || total == 1)
                return true;
            if (x < total || total == 0 || x % total == 0)
                return false;
            x %= total;
            total += x;
            pq.push(x);
        }
    }
};