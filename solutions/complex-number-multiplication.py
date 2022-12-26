// https://leetcode.com/problems/complex-number-multiplication

class Solution:
    def complexNumberMultiply(self, a: str, b: str) -> str:
        z = eval(('(%s)*(%s)' % (a, b)).replace('i', 'j'))
        return '%d+%di' % (z.real, z.imag)
        