// https://leetcode.com/problems/apply-discount-to-prices

def isfloat(s):
    try: 
        float(s)
    except ValueError: 
        return False
    return True
class Solution:
    def discountPrices(self, s: str, d: int) -> str:
        l = s.split()
        ans=""
        for x in l:
            if(x[0]=='$' and isfloat(x[1:])):
                f=float(x[1:])
                f-=(f*d)/100
                f=format(f,'.2f')
                # print(f)
                ans+='$'+str(f)
            else:
                ans+=x
            ans+=" "
        return ans[:-1]