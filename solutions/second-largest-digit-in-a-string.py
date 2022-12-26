// https://leetcode.com/problems/second-largest-digit-in-a-string

class Solution:
    def secondHighest(self, s: str) -> int:
        first = second = -1
        for c in s:
            if c.isdigit():
                d = int(c)
                if d > first:
                    first, second = d, first
                elif first > d > second:
                    second = d
        return second