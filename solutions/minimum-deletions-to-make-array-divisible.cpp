// https://leetcode.com/problems/minimum-deletions-to-make-array-divisible

class Solution {
public:
    int minOperations(vector<int>& a, vector<int>& b) {
        int g = -1;
        for(auto x:b) {
            if(g==-1) g=x;
            else g=__gcd(g,x);
        }
        map<int,int> cnt;
        for(auto x:a) cnt[x]++;
        int ans = 0;
        for(auto it:cnt) {
            if(g%it.first==0) {
                return ans;
            }
            ans+=it.second;
        }
        return -1;
    }
};