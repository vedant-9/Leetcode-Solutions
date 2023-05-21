class Solution:
    def minLength(self, s: str) -> int:
        while(1):
            t = s
            s = s.replace("AB", "")
            s = s.replace("CD", "")
            if(t == s):
                break
        return len(s)
