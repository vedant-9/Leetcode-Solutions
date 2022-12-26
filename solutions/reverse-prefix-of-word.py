// https://leetcode.com/problems/reverse-prefix-of-word

class Solution:
    def reversePrefix(self, s: str, ch: str) -> str:
        i = s.find(ch)
        ans = ""
        if(i!=-1):
            ans += s[i::-1]
            ans += s[i+1:]
            return ans
        return s