class Solution:
    def countSeniors(self, details: List[str]) -> int:
        cnt = 0
        for x in details:
            if int(x[11]+x[12]) > 60:
                cnt += 1
        return cnt
