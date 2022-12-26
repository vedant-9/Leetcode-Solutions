// https://leetcode.com/problems/maximum-performance-of-a-team

class Solution {
public:
    // Note don't take max after doing module on curPerformance
    const int mod = 1e9+7;
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++) {
            v.push_back({efficiency[i], speed[i]});
        }
        
        // According to efficiency with descending order 
        // so that each eff can be treated as min eff till
        sort(v.rbegin(), v.rend());
        
        // pq will store k minimums till
        priority_queue<int, vector<int>, greater<int>> pq;
        
        long speedSum = 0, maxPerformance = 0;
        for(auto &[e, s]: v) {
            pq.push(s);
            speedSum += s;
            
            if(pq.size() > k) {
                speedSum -= pq.top();
                pq.pop();
            }
            
            int minEfficiency = e;
            long curPerformance = (speedSum * minEfficiency);
            
            maxPerformance = max(maxPerformance, curPerformance);
        }
        
        return maxPerformance % mod;
    }
};