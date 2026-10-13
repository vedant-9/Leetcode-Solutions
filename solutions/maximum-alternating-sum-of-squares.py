class Solution:
    def maxAlternatingSum(self, nums: List[int]) -> int:
        nums = [abs(x) for x in nums]
        nums.sort()
        score = 0
        n = len(nums)
        for i in range(n):
            if i < n//2:
                score -= nums[i]*nums[i]
            else:
                score += nums[i]*nums[i]
        return score
