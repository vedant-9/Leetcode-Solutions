// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    long long minimumTime(vector<int>& a, int req) {
        // int t = 1;
        // while(1) {
        //     int tot=0;
        //     for(auto x:a) tot+=t/x;
        //     if(tot>=req) return t;
        //     t++;
        // }
        // return 0;
        long long low = 1, high = (long long)*min_element(a.begin(),a.end())*req;
        while(low<high) {
            long long mid = low+(high-low)/2;
            long long tot = 0;
            for(auto x:a) tot+=mid/x;
            if(tot<req) low=mid+1;
            else high=mid;
        }
        return low;
    }
};