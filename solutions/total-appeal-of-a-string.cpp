// https://leetcode.com/problems/total-appeal-of-a-string

#define ll long long
class Solution {
public:
    long long appealSum(string s) {
        ll n = s.length();
        ll ans = 0;
        for(ll i=0;i<n;i++) {
            ans+=(n-i)*(i+1);
        }
        map<char,ll> mp;
        for(ll i=0;i<n;i++) {
            if(mp.find(s[i])!=mp.end()) {
                ans -= (n-i)*(mp[s[i]]+1);
            }
            mp[s[i]]=i;
        }
        return ans;
    }
};