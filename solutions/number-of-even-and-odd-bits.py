class Solution:
    def evenOddBit(self, n: int) -> List[int]:
        b = list(map(int, bin(n)[2:]))
        return [sum(b[-1::-2]), sum(b[-2::-2])]
