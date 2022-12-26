// https://leetcode.com/problems/number-of-valid-words-in-a-sentence

class Solution:
    def countValidWords(self, s: str) -> int:
        l = s.split()
        ans=0
        for x in l:
            d=0
            f1,f2,f3=0,0,0
            for i in x:
                if i>='0' and i<='9':
                    d+=1
            if(d==0):
                f1=1
            
            if(x.count('-')<=1):
                idx = x.find('-')
                if(idx==-1):
                    f2=1
                elif(idx-1>=0 and idx+1<len(x) and x[idx-1]>='a' and x[idx-1]<='z' and x[idx+1]>='a' and x[idx+1]<='z'):
                    f2=1
            
            p = 0
            for i in x:
                if i in "!.,":
                    p+=1
            if(p==0 or (p==1 and x[-1] in "!.,")):
                f3=1
            ans+=(f1+f2+f3==3)
        return ans