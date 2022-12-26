// https://leetcode.com/problems/find-the-k-beauty-of-a-number

class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string s = to_string(num);
        int n = s.length(),ans=0;
        for(int i=0;i<=n-k;i++) {
            string x = s.substr(i,k);
            int y = stoll(x);
            if(y and num%y==0) ans++;
        }
        return ans;
    }
};