// https://leetcode.com/problems/minimum-time-to-make-rope-colorful

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int i = 0, totalTime = 0;
        while(i<n) {
            int j = i, groupTime = 0, maxTime = 0;
            while(i<n and colors[i] == colors[j]) {
                groupTime += neededTime[i];
                maxTime = max(maxTime, neededTime[i]);
                i++;
            } 
            totalTime += (groupTime - maxTime);
        } 
        return totalTime;
    }
};