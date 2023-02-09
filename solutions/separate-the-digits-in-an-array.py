class Solution:
    def separateDigits(self, nums: List[int]) -> List[int]:
        ans = []
        for x in nums:
            for t in str(x):
                y = int(t)
                ans.append(y)
        return ans
