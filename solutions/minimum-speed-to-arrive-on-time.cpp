// https://leetcode.com/problems/minimum-speed-to-arrive-on-time

class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if(hour <= (double) (n-1)) return -1;
        
        auto canReach = [&](int speed)->bool{
            double time = 0;
            for(int i=0; i<n-1; i++) {
                time += (dist[i]+speed-1)/speed;
            }
            time += ((double)(dist[n-1]))/speed;
            return time <= hour;
        };
        
        int low = 1, high = 1e7;
        while(low < high) {
            int mid = (low+high)/2;
            
            if(canReach(mid)) high = mid;
            else low = mid+1;
        }
        
        return high;
    }
};