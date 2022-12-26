// https://leetcode.com/problems/longest-binary-subsequence-less-than-or-equal-to-k

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n=s.size();
        reverse(s.begin(),s.end());
        int cnt=0;
        long long val=0;
        for(int i=0;i<n;i++){
            long long num=s[i]-'0';
            if((num*pow(2,cnt)+val)<=k){
                val=val+num*pow(2,cnt);
                cnt++;
            }
        }
        return cnt;
    }
};