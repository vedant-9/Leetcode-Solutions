class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long low = 0, high = 1e17;
        while(low <= high) {
            long long mid = low + (high-low)/2;
            
            long long carsRepaired = 0;
            for(auto x: ranks) {
                carsRepaired += sqrt(mid/x);
            }
            
            if(carsRepaired >= cars) high = mid-1;
            else low = mid+1;
        }
        return high+1;
    }
};
