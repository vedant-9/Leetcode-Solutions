// https://leetcode.com/problems/4sum-ii

class Solution {
public:
    int fourSumCount(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d) {
        unordered_map<int, int>  abSum;
        for(auto i : a) {
            for(auto j : b) {
                abSum[i+j]++;
            }
        }
        
        int count = 0;
        for(auto k : c) {
            for(auto l : d) {
                auto it = abSum.find(0 - k - l);
                if(it != abSum.end()) {
                    count += it->second;
                }
            }
        }
        
        return count;
    }
};