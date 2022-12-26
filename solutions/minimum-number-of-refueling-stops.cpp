// https://leetcode.com/problems/minimum-number-of-refueling-stops

class Solution {
public:
    // amount of fuel we have at end at total will be total dist we travelled
    int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations) {
        int i = 0, stops = 0;
        int curDist = startFuel;
        
        priority_queue<int> pq;
        while(curDist < target) {
            // push all stations which are less than curDist
            while (i < stations.size() && stations[i][0] <= curDist)
                pq.push(stations[i][1]),i++;
            
            // will take a stop at station which has highest fuel
            if (pq.empty()) 
                return -1;
            curDist += pq.top(); pq.pop();
            stops++;
        }
        return stops;
    }
};