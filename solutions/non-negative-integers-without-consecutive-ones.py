// https://leetcode.com/problems/non-negative-integers-without-consecutive-ones

class Solution:
    def findIntegers(self, n: int) -> int:
        x, y = 1, 2
        res = 0
        n += 1
        while n:
            if n & 1 and n & 2:
                res = 0
            res += x * (n & 1)
            n >>= 1
            x, y = y, x + y
        return res
        