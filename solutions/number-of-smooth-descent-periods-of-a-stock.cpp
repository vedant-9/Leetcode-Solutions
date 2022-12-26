// https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock

class Solution {
public:
    long long getDescentPeriods(vector<int>& a) {
        int n=a.size();
        long long ans=0,c=1;
        for(int i=1;i<n;i++) {
            if(a[i]==a[i-1]-1) {
                c++;
            } else {
                ans+=(c*(c+1))/2;
                c=1;
            }
        }
        ans+=(c*(c+1))/2;
        return ans;
    }
};