// https://leetcode.com/problems/number-of-rectangles-that-can-form-the-largest-square

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        max_len = float('-inf')
        count = 0
        for item in rectangles:
            min_len = min(item)
            if min_len == max_len:
                count += 1
            elif min_len > max_len:
                max_len = min_len
                count = 1

        return count