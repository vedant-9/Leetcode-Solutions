// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n = quality.size();
        
        vector<pair<double, int>> workers;
        for(int i=0; i<n; i++) {
            double ratio = wage[i]*1.0/quality[i];
            workers.push_back({ratio, quality[i]});
        }
        
        // sort according to ratio 
        sort(workers.begin(), workers.end());
        
        // max-heap will store max quality till
        priority_queue<int> pq;
        
        double res = DBL_MAX;
        int qualitySum = 0;
        for(auto &[r, q]: workers) {
            pq.push(q);
            qualitySum += q;
            
            if(pq.size() > k) {
                qualitySum -= pq.top();
                pq.pop();
            }
            
            if(pq.size() == k) {
                res = min(res, r * qualitySum);
            }
        }
        
        return res;
    }
};