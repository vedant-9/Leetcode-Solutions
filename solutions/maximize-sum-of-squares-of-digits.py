class Solution:
    def maxSumOfSquares(self, num: int, sum: int) -> str:
        if 9 * num < sum:
            return ""
        res = ""
        while sum > 0:
            if sum <= 9:
                res += str(sum)
                sum = 0
            else:
                res += "9"
                sum -= 9
            num -= 1
        while num > 0:
            res += "0"
            num -= 1
        return res
        
