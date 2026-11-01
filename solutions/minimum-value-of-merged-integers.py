class Solution:
    def minMergedInteger(self, nums: list[int]) -> int:
        l = []
        for i in range(0,len(nums),2):
            l.append(int(str(nums[i]) + str(nums[i+1])))
        return sorted(l)[0]
