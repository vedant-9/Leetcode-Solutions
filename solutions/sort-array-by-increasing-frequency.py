// https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution:
    def frequencySort(self, nums: List[int]) -> List[int]:
        r = Counter(nums)
        return sorted(nums, key=lambda x: (r[x], -x))