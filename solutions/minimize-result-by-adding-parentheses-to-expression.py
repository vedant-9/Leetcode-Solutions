// https://leetcode.com/problems/minimize-result-by-adding-parentheses-to-expression

class Solution:
    def minimizeResult(self, s: str) -> str:
        p,n = 0,len(s)
        while(p<n and s[p]!='+'):
            p+=1
        # print(p)
        ans = 0
        anss = "."
        for i in range(0,p):
            for j in range(p+2,n+1):
                if(i==0): 
                    x=1
                else:
                    x=int(s[:i])
                if(j==n):
                    y=1
                else:
                    y=int(s[j:n])
                tans = x*(int(s[i:p])+int(s[p+1:j]))*y
                # print(tans)
                if(anss=="." or tans<ans):
                    ans=tans
                    anss=s[:i]+"("+s[i:p]+"+"+s[p+1:j]+")"+s[j:n]
        return anss
                    