// https://leetcode.com/problems/self-dividing-numbers

def is_self_dividing(x):
    s = str(x)
    for d in s:
        if d=="0" or x%int(d)!=0:
            return False
    return True

class Solution:
    
    
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        ans = []
        for x in range(left, right+1):
            if is_self_dividing(x):
                ans.append(x)
        return ans