// https://leetcode.com/problems/minimum-cost-of-buying-candies-with-discount

class Solution {
public:
    int minimumCost(vector<int>& a) {
        int ans = 0, n = a.size();
        sort(a.begin(),a.end());
        int i=n-1;
        while(i>=0) {
            if(i-1>=0) ans+=a[i]+a[i-1];
            else if(i>=0) ans+=a[i];
            i-=3;
        }
        return ans;
    }
};