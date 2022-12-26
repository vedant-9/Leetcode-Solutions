// https://leetcode.com/problems/longest-consecutive-sequence

class Solution {
public:
    int longestConsecutive(vector<int>& a) {
        unordered_set<int> s(a.begin(),a.end());
        
        int mx = 0;
        
        for(auto x:a) {
            if(s.count(x-1)) continue;
            
            int c = 0, cur = x;
            while(s.count(cur)) {
                cur++;
                c++;
            }
            
            mx = max(mx, c);
        }
        
        return mx;
    }
};