// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array

class Solution:
    def kthLargestNumber(self, a: List[str], k: int) -> str:
        b = [int(x) for x in a]
        b.sort()
        return str(b[-k])