// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word

class Solution:
    def numOfStrings(self, p: List[str], s: str) -> int:
        c = 0
        for x in p:
            if x in s:
                c+=1
        return c