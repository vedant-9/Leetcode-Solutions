// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    int minEatingSpeed(vector<int>& a, int h) {
        int n = a.size();
        int low = 1, high = 1e9;
        while(low<high) {
            int mid = low+(high-low)/2;
            
            int tot = 0;
            for(auto x:a) {
                tot+=(x+mid-1)/mid;
            }
            
            if(tot>h)
                low=mid+1;
            else 
                high=mid;
        }
        return low;
    }
};