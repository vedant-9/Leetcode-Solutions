// https://leetcode.com/problems/minimum-non-zero-product-of-the-array-elements

class Solution:
    def minNonZeroProduct(self, p: int) -> int:
        def power(a, b):
            if b == 0:
                return 1
            ret = power(a, b>>1)
            ret = (ret*ret)%1000000007
            if b&1:
                ret = (ret*a)%1000000007
            return ret
        
        return (power(2**p-2, 2**(p-1)-1)*(2**p-1))%1000000007