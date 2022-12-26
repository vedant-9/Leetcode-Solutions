// https://leetcode.com/problems/minimum-number-of-moves-to-seat-everyone

class Solution {
public:
    int minMovesToSeat(vector<int>& a, vector<int>& b) {
        int ans=0, n = a.size();
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        for(int i=0;i<n;i++) {
            ans+=abs(a[i]-b[i]);
        }
        return ans;
    }
};