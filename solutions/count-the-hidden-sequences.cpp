// https://leetcode.com/problems/count-the-hidden-sequences

class Solution {
public:
    int numberOfArrays(vector<int>& a, int l, int u) {
        long long sum = 0;
        long long mx=max(0,a[0]),mn=min(0,a[0]);
        for(auto x:a) {
            sum+=x;
            mx=max(mx,sum);
            mn=min(mn,sum);
        }
        long long ans = (u-l+1)-(mx-mn);
        return (ans>0?ans:0);
    }
};