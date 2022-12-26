// https://leetcode.com/problems/maximum-product-after-k-increments

const int M=1e9+7;
class Solution {
public:
    int maximumProduct(vector<int>& a, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto x:a) pq.push(x);
        while(k--) {
            auto cur=pq.top(); pq.pop();
            pq.push(cur+1);
        }
        long long ans = 1;
        while(!pq.empty()) {
            auto cur=pq.top(); pq.pop();
            ans=(ans*cur)%M;
        }
        return ans;
    }
};