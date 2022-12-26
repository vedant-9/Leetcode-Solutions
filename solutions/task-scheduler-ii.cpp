// https://leetcode.com/problems/task-scheduler-ii

class Solution {
public:
    long long taskSchedulerII(vector<int>& tasks, int space) {
        long long day = 0;
        space++;
        map<long long, long long> mp;
        
        for(auto &x: tasks) {
            day++;
            if(mp.find(x) != mp.end()) {
                long long diff = day - mp[x];
                if(diff < space) {
                    day += (space-diff);
                }
            }
            mp[x] = day;
        }
        return day;
    }
};