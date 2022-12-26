// https://leetcode.com/problems/vowels-of-all-substrings

class Solution {
public:
    long long countVowels(string s) {
        long long cnt=0,n=s.size();
        for(int i=0;i<n;i++) {
            char c=s[i];
            if(c=='a' or c=='e' or c=='i' or c=='o' or c=='u')
                cnt+=(i+1)*(n-i);
        }
        return cnt;
    }
};