// https://leetcode.com/problems/minimum-sum-of-four-digit-number-after-splitting-digits

class Solution:
    def minimumSum(self, s: int) -> int:
        res = ''.join(sorted(str(s)))
        s = str(res)
        ans = [int(s[:1])+int(s[1:]),int(s[:2])+int(s[2:]),int(s[:3])+int(s[3:]),int(s[0]+s[2])+int(s[1]+s[3])]
        return min(ans)