// https://leetcode.com/problems/minimum-number-of-operations-to-convert-time

class Solution:
    def convertTime(self, cur: str, cor: str) -> int:
        x = int(cur[:2])*60+int(cur[3:])
        y = int(cor[:2])*60+int(cor[3:])
        d = y-x
        l = [60,15,5,1]
        ans = 0
        for i in l:
            if(d==0):
                break
            ans += d//i
            d = d%i
        return ans