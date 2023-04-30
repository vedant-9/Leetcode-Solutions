class Solution:
    def findThePrefixCommonArray(self, A: List[int], B: List[int]) -> List[int]:
        l = len(A)
        ans = []
        s1, s2 = set(), set()
        for i in range(l):
            s1.add(A[i])
            s2.add(B[i])
            ans.append(len(s1 & s2))
        return ans
