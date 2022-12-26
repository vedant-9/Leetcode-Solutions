// https://leetcode.com/problems/maximum-value-of-a-string-in-an-array

class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        max_value = 0
        for string in strs:
            if string.isdigit():
                value = int(string)
            else:
                value = len(string)
            max_value = max(max_value, value)
        return max_value