// https://leetcode.com/problems/count-special-integers

import numpy as np
def count_num_with_DupDigits(n) -> int:
    n_str = str(n)
    n_len = len(n_str)
    n_unique = 0

    if n > 10:
        for i in range(n_len-1):
            n_unique = n_unique + 9*int(np.math.factorial(9)/np.math.factorial(10-n_len+i+1))
        m=0
        if m == 0:
            n_first  = (int(n_str[m])-1)*int(np.math.factorial(9)/np.math.factorial(10-n_len))
        m=m+1
        count_last=0
        n_sec=0


        for k in range(n_len-1):
            if m == n_len-1:
                count_last = int(n_str[m])+1
                for l in range(int(n_str[m])+1):
                    if n_str[0:n_len-1].count(str(l)) > 0:
                        count_last = count_last-1
            else:
                for s in range(int(n_str[k+1])):
                    if n_str[0:k+1].count(str(s))>0:
                        n_sec=n_sec
                    else:
                        n_sec = int(np.math.factorial(9-m)/np.math.factorial(10-n_len))+n_sec
                if n_str[0:k+1].count(n_str[k+1]) > 0:
                    break
                m= m+1
        value=n-(n_sec+n_first+n_unique+count_last)
    else:
        value = 0
    return value


class Solution:
    def countSpecialNumbers(self, n: int) -> int:
        l = count_num_with_DupDigits(n)
        return n-l