// https://leetcode.com/problems/count-hills-and-valleys-in-an-array

class Solution {
public:
    int countHillValley(vector<int>& a) {
        a.erase(unique(a.begin(),a.end()),a.end());
        int ans = 0, n = a.size();
        for(int i=1;i<n-1;i++) {
            if(a[i]<a[i-1] and a[i]<a[i+1]) ans++;
            else if(a[i]>a[i-1] and a[i]>a[i+1]) ans++;
        }
        return ans;
    }
};