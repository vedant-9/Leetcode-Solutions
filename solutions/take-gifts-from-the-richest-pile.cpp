class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int> pq;
        for(auto x: gifts) pq.push(x);
        long long ans = 0;
        while(k--) {
            auto x = pq.top(); pq.pop();
            pq.push(sqrt(x));
        }
        while(!pq.empty()) ans += pq.top(), pq.pop();
        return ans;
    } 
};
