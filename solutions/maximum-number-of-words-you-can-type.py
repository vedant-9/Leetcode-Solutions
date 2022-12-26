// https://leetcode.com/problems/maximum-number-of-words-you-can-type

class Solution:
    def canBeTypedWords(self, s: str, bl: str) -> int:
        l = s.split()
        ans = 0
        for i in l:
            f=1
            for j in i:
                if j in bl:
                    f=0
                    break
            ans += f
        return ans
        